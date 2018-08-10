#ifndef _MUSICBOX_H_
#define _MUSICBOX_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

class MusicBox : public Ref
{
private:
	unsigned int m_nSoundId;

public:
	MusicBox();
	~MusicBox();
	virtual bool init();

public:
	/*Flag:
	*0:��������		10����������		�Զ���
	*1:ֹͣ����		11����������		19: backMusic1
	*2:��ͣ����		12����������
	*3:�ָ�����		13����������
	*4:���²���		14����ͣ��Ч
	*5:�������		15���ָ���Ч
	*6:������Ч		16����ͣ������Ч
	*7:������Ч		17���ָ�������Ч
	*8:ֹͣ����		18��ֹͣ������Ч
	*9:ȥ����Ч		
	*/
	void musicFlagListener(int flag);

	//then set musicFlagListener
	//or��createWithMusicFlag��
	static MusicBox* create();

   /*now play music
    *Flag:
	*0:��������		10����������		�Զ���
	*1:ֹͣ����		11����������		19: backMusic1
	*2:��ͣ����		12����������		20: backMusic2
	*3:�ָ�����		13����������
	*4:���²���		14����ͣ��Ч
	*5:�������		15���ָ���Ч
	*6:������Ч		16����ͣ������Ч
	*7:������Ч		17���ָ�������Ч
	*8:ֹͣ����		18��ֹͣ������Ч
	*9:ȥ����Ч		
	*/
	static MusicBox* createWithMusicFlag(int flag);

};
#endif
