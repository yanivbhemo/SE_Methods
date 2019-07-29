#include "../Common/Graphics.h"
#include "../Controls/Label.h"
#include "../Controls/Panel.h"
#include "../Common/Border/Double.h"
#include "../Common/Border/Single.h"
#include "../Common/EventEngine.h"
#include "../Controls/Button.h"
#include "../Controls/NumericBox.h"

int main(int argc, char** argv)
{
	Label lMain("Welcome to our AMA project");
	Label l("I'm Panel");
	Panel p(0, 0, 50, 30, new Double, Color::White, Color::Red);
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

	p.addToPanel(&lMain);
	p.addToPanel(&l);
	p1.addToPanel(&l2);
	p.addToPanel(&p1);
	p.addToPanel(&btn);
	p.addToPanel(&lNumeric);
	p.addToPanel(&numeric);

	EventEngine e;
	e.run(p);
}