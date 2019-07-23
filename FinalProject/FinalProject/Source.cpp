#include "../Common/Graphics.h"
#include "../Controls/Label.h"
#include "../Controls/Panel.h"
#include "../Common/Border/Double.h"
#include "../Common/Border/Single.h"
#include "../Common/EventEngine.h"

int main(int argc, char** argv)
{
	Border* d = new Double;
	Label l(2, 2, 2, 2, d, Color::Black, Color::Blue, "Hello World");
	Border* s = new Single;
	Panel p(0, 0, 30, 30, d, Color::White, Color::Red);
	Panel p1(5, 5, 10, 10, s, Color::Cyan, Color::Purple);
	Control& l2 = l;
	p1.addToPanel(&l2);
	p.addToPanel(&p1);
	p.addToPanel(&l2);
	EventEngine e;
	e.run(p);
}