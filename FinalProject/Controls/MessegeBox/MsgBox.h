#pragma once

#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include "../Label/Label.h"



class MsgBox : public Panel
{	
	class AcceptListener : public MouseListener {		
		public: 
			AcceptListener(Control& c) : _c(c) {}
			void mousePressed(Control& b, short x, short y, bool isLeft) {		
				_c.hide();
				MsgBox& that = dynamic_cast<MsgBox&>(_c);
				that.setResult(true);
			}	
		private:
			Control& _c;			
	};	
	class DeclineListener : public MouseListener {
	public:
		DeclineListener(Control& c) : _c(c) {}
		void mousePressed(Control& b, short x, short y, bool isLeft) {
			_c.hide();
			MsgBox& that = dynamic_cast<MsgBox&>(_c);
			that.setResult(false);
		}
	private:
		Control& _c;
	};
			
	boolean result;
	public:
		MsgBox(int height, int width);
		void setText(string text);
		void setTitle(string text);
		void mousePressed(short, short, bool);
		void keyDown(WORD, CHAR);
		void show();
		void hide();
		void setResult(bool b);
		inline boolean getResult() { return result; };
};

