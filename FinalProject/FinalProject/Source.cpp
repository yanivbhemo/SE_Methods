#include <iostream> 
#include <vector>
#include "../Common/Graphics.h"
#include "../Controls/Label.h"
#include "../Controls/Panel.h"
#include "../Common/Border/Double.h"
#include "../Common/Border/Single.h"
#include "../Common/EventEngine.h"
#include "../Controls/Button.h"
#include "../Controls/NumericBox.h"
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

	Button btn("I'm Button");
	btn.setTop(3);
	btn.setLeft(1);
	// btn.setBorder(new Single);

	Label lNumeric("I'm Numeric Box");
	NumericBox numeric(0, 9, 38, 6);
	lNumeric.setLeft(33);
	lNumeric.setTop(3);

	Label checkListlbl("Check List:");
	checkListlbl.setLeft(4);
	checkListlbl.setTop(20);
	vector<string> options;
	options.push_back("Option 1");
	options.push_back("Option 2");
	options.push_back("Option 3");
	options.push_back("Option 4");
	CheckList ch1(5, 22, options);
	ch1.AddSelectedItem("Option 55");

	Label radioListlbl("Radio List:");
	radioListlbl.setLeft(32);
	radioListlbl.setTop(20);
	vector<Button> radio_list_options;
	radio_list_options.push_back(Button("() Radio 1"));
	radio_list_options.push_back(Button("() Radio 2"));
	radio_list_options.push_back(Button("() Radio 3"));
	radio_list_options.push_back(Button("() Radio 4"));
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
	p.addToPanel(&rl1);
	p.addToPanel(&radioListlbl);

	EventEngine e;
	e.run(p);
}