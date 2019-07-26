#include "../Common/Graphics.h"
#include "../Controls/Label.h"
#include "../Controls/Panel.h"
#include "../Common/Border/Double.h"
#include "../Common/Border/Single.h"
#include "../Common/EventEngine.h"
#include "../Controls/Button.h"

int main(int argc, char** argv)
{
	Border* d = new Double;
	Label l("Hello World");
	Border* s = new Single;
	Panel p(0, 0, 30, 30, d, Color::White, Color::Red);
	Panel p1(5, 5, 10, 10, s, Color::Cyan, Color::Purple);
	Control& l2 = l;
	Button plus("+");

	// p1.addToPanel(&l2);
	p.addToPanel(&p1);
	p.addToPanel(&l2);
	p.addToPanel(&plus);
	EventEngine e;
	e.run(p);
}