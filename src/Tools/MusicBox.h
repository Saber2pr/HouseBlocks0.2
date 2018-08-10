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
	*0:播放音乐		10：增加音量		自定义
	*1:停止播放		11：降低音量		19: backMusic1
	*2:暂停播放		12：增加音量
	*3:恢复播放		13：降低音量
	*4:重新播放		14：暂停音效
	*5:检查音乐		15：恢复音效
	*6:播放音效		16：暂停所有音效
	*7:播放音效		17：恢复所有音效
	*8:停止播放		18：停止所有音效
	*9:去除音效		
	*/
	void musicFlagListener(int flag);

	//then set musicFlagListener
	//or‘createWithMusicFlag’
	static MusicBox* create();

   /*now play music
    *Flag:
	*0:播放音乐		10：增加音量		自定义
	*1:停止播放		11：降低音量		19: backMusic1
	*2:暂停播放		12：增加音量		20: backMusic2
	*3:恢复播放		13：降低音量
	*4:重新播放		14：暂停音效
	*5:检查音乐		15：恢复音效
	*6:播放音效		16：暂停所有音效
	*7:播放音效		17：恢复所有音效
	*8:停止播放		18：停止所有音效
	*9:去除音效		
	*/
	static MusicBox* createWithMusicFlag(int flag);

};
#endif
