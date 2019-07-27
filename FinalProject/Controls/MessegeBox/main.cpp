#include <iostream>
#include "MsgBox.h"
#include "../EventEngine/EventEngine.h"
#include "../ComboBox/ComboBox.h"
#include "../TextBox/TextBox.h"

using namespace std;

int main(int argc, char **argv) {

	Panel p(30, 60);
	p.setLocation({ 10, 10 });
	p.setBorder(BorderType::Single);
	vector<string> strings;
	strings.push_back("item1");
	strings.push_back("item2");
	strings.push_back("item3");
	strings.push_back("item4");
	strings.push_back("item5");
	ComboBox cName(40, strings);
	cName.setBorder(BorderType::Double);
	Control::setFocus(&cName);
	cName.setBackGround(BackgroundColor::Orange);
	cName.setForeground(ForegroundColor::Blue);
	p.addControl(&cName, 15, 15);

	
	MsgBox *msgBox = new MsgBox(10, 20);
	msgBox->setBorder(BorderType::Double);
	p.addControl(msgBox, 15, 20);
	

	TextBox tName(20);
	tName.setValue("Sherlock Holmes sfasaf");
	tName.setBorder(BorderType::Double);
	tName.setBackGround(BackgroundColor::Red);
	tName.setForeground(ForegroundColor::Cyan);
	Control::setFocus(&tName);
	p.setBorder(BorderType::Double);
	p.addControl(&tName, 15, 20);

	Control::setFocus(msgBox);
	EventEngine engine;
	engine.run(p);
	return 0;
	
}