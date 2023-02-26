#include "FlowWord.h"

void FlowWord::showWord(const char* text, CCPoint position) {//text为飘字的内容，pos为飘字的位置  
	/*初始化*/
	label = CCLabelTTF::create(text, "Arial", 10);//创建一个字体为Arial，字号为18，内容为text的CCLabelTTF，也就是标签文本  
	label->setColor(ccc3(255, 0, 0));//设置其颜色为红色
	label->setPosition(position);//设置其位置  
	this->addChild(label);//在场景上添加这个标签文本  
	/*三个动作，放大->移动->缩小*/
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();//获取屏幕的尺寸、位置信息等       
	CCFiniteTimeAction* action1 = CCScaleTo::create(0.2f, 3.0f, 3.0f);//0.2s内在x、y上方向皆放大为原尺寸的3倍  
	CCFiniteTimeAction* action2 = CCMoveTo::create(0.3f, ccp(visibleSize.width / 4, 3 * visibleSize.height / 4));//在0.3s内，移动到坐标为(x=屏幕宽度的25%，y=屏幕高度的75%处)  
	CCFiniteTimeAction* action3 = CCScaleTo::create(0.2f, 0.1f, 0.1f);//之后在0.2s内在x、y上皆缩小为原尺寸的0.1倍  
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(FlowWord::flowEnd));//声明一个回调（处理）函数，为FlowWord类中的flowEnd()  
	CCFiniteTimeAction* action = CCSequence::create(action1, action2, action3, callFunc, NULL);//以上的所有动作组成动作序列action  
	/*对label实行action这个动作*/
	label->runAction(action);
}

void FlowWord::flowEnd() {//动作结束，从父节点中删除自身  
	label->setVisible(false);//先隐藏显示  
	label->removeFromParentAndCleanup(true);//再删除  
}