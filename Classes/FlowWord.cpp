#include "FlowWord.h"

void FlowWord::showWord(const char* text, CCPoint position) {//textΪƮ�ֵ����ݣ�posΪƮ�ֵ�λ��  
	/*��ʼ��*/
	label = CCLabelTTF::create(text, "Arial", 10);//����һ������ΪArial���ֺ�Ϊ18������Ϊtext��CCLabelTTF��Ҳ���Ǳ�ǩ�ı�  
	label->setColor(ccc3(255, 0, 0));//��������ɫΪ��ɫ
	label->setPosition(position);//������λ��  
	this->addChild(label);//�ڳ�������������ǩ�ı�  
	/*�����������Ŵ�->�ƶ�->��С*/
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();//��ȡ��Ļ�ĳߴ硢λ����Ϣ��       
	CCFiniteTimeAction* action1 = CCScaleTo::create(0.2f, 3.0f, 3.0f);//0.2s����x��y�Ϸ���ԷŴ�Ϊԭ�ߴ��3��  
	CCFiniteTimeAction* action2 = CCMoveTo::create(0.3f, ccp(visibleSize.width / 4, 3 * visibleSize.height / 4));//��0.3s�ڣ��ƶ�������Ϊ(x=��Ļ��ȵ�25%��y=��Ļ�߶ȵ�75%��)  
	CCFiniteTimeAction* action3 = CCScaleTo::create(0.2f, 0.1f, 0.1f);//֮����0.2s����x��y�Ͻ���СΪԭ�ߴ��0.1��  
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(FlowWord::flowEnd));//����һ���ص�������������ΪFlowWord���е�flowEnd()  
	CCFiniteTimeAction* action = CCSequence::create(action1, action2, action3, callFunc, NULL);//���ϵ����ж�����ɶ�������action  
	/*��labelʵ��action�������*/
	label->runAction(action);
}

void FlowWord::flowEnd() {//�����������Ӹ��ڵ���ɾ������  
	label->setVisible(false);//��������ʾ  
	label->removeFromParentAndCleanup(true);//��ɾ��  
}