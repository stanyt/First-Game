#ifndef __FLOWWORD_H__
#define __FLOWWORD_H__
#include "cocos2d.h"

USING_NS_CC;

class FlowWord :public CCNode {
public:
    void showWord(const char* text, CCPoint pos);//Ʈ�ַ�����textΪƮ�ֵ����ݣ�posΪƮ�ֵ�λ��  
private:
    CCLabelTTF* label;//���Ա  
    void flowEnd();//Ʈ�ֽ���ʱ�Ļص���������������Ҫ����ɾ���Լ�      
};
#endif// #pragma once
