#include <iostream> 
#include <vector>
#include "../Common/Graphics.h"
#include "../Controls/Label.h"
#include "../Controls/Panel.h"
#include "../Common/Border/Border.h"
#include "../Common/EventEngine.h"
#include "../Controls/Button.h"
#include "../Controls/NumericBox.h"
#include "../Controls/MessageBox.h"
#include "../Controls/CheckList.h"
#include "../Controls/TextBox.h"
#include "../Controls/RadioList.h"

int main(int argc, char** argv)
{
	
	Label lMain("Welcome to our AMA project");
	Label l("I'm Panel");
	Panel p(0, 0, 80, 60, new Double, Color::White, Color::Red);
	l.setTop(0);
	l.setLeft(38);

	Label l2("I'm another Panel");
	Panel p1(5, 10, 20, 10, new Single, Color::Cyan, Color::Purple);

	messageBox msg("Welcome to Message Box");
	msg.SetVisability(true);
	msg.setLeft(33);
	msg.setTop(10);

	Button btn("I'm Button");
	btn.setTop(3);
	btn.setLeft(1);

	Label lNumeric("I'm Numeric Box");
	NumericBox numeric(0, 9, 38, 6);
	lNumeric.setLeft(33);
	lNumeric.setTop(3);

	Label checkListlbl("Check List:");
	checkListlbl.setLeft(4);
	checkListlbl.setTop(20);
	vector<string> check_list_options;
	check_list_options.push_back("[ ] Option 1");
	check_list_options.push_back("[ ] Option 2");
	check_list_options.push_back("[ ] Option 3");
	check_list_options.push_back("[ ] Option 4");
	CheckList ch1(5, 22, check_list_options);
	//ch1.AddSelectedItem("Option 55");

	Label radioListlbl("Radio List:");
	radioListlbl.setLeft(32);
	radioListlbl.setTop(20);
	vector<string> radio_list_options;
	radio_list_options.push_back("() Radio 1");
	radio_list_options.push_back("() Radio 2");
	radio_list_options.push_back("() Radio 3");
	radio_list_options.push_back("() Radio 4");
	RadioList rl1(33, 22, radio_list_options);

	//TextBox txt1(10,10,30);

	p.addToPanel(&lMain);
	p.addToPanel(&l);
	p1.addToPanel(&l2);
	p.addToPanel(&p1);
	p.addToPanel(&btn);
	p.addToPanel(&lNumeric);
	p.addToPanel(&numeric);
	p.addToPanel(&checkListlbl);
	p.addToPanel(&ch1);
	p.addToPanel(&radioListlbl);
	p.addToPanel(&rl1);
	p.addToPanel(&msg);

	EventEngine e;
	// system("MODE x, y");
	e.run(p);
}