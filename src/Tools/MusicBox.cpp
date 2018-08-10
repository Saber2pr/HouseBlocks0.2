#include "MusicBox.h"



MusicBox::MusicBox()
{
}


MusicBox::~MusicBox()
{
}


bool MusicBox::init()
{
	//音效文件
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	#define MUSIC_FILE        "backMusic.mp3"
	#define MUSIC_FILE1        "backMusic1.mp3"
	#define MUSIC_FILE2        "backMusic2.mp3"
	#define EFFECT_FILE        "backMusic.mp3"
	#endif

	//音乐文件
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	#define MUSIC_FILE        "backMusic.mp3"
	#define MUSIC_FILE1        "backMusic1.mp3"
	#define MUSIC_FILE2        "backMusic2.mp3"
	#define EFFECT_FILE        "backMusic.mp3"
    #endif

	return true;
}

void MusicBox::musicFlagListener(int flag)
{
	switch (flag)
	{
		// 背景音乐部分:
	case 0:
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE, true);   //播放
		break;
	case 1:
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();  // 停止播放
		break;
	case 2:
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();   //暂停播放
		break;
	case 3:
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();   // 恢复播放
		break;
	case 4:
		SimpleAudioEngine::getInstance()->rewindBackgroundMusic();   //从头重新播放
		break;
	case 5:
		if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())    //判断当前是否播放背景音乐
		{
			CCLOG("background music is playing");
		}
		else
		{
			CCLOG("background music is not playing");
		}
		break;
		// 音效部分
	case 6:
	{
		m_nSoundId = SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE); //播放
	}  
	break;
	case 7:
	{
		m_nSoundId = SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE, true);
	}
		break;
	case 8:
		SimpleAudioEngine::getInstance()->stopEffect(m_nSoundId);   //停止播放
		break;
	case 9:
		SimpleAudioEngine::getInstance()->unloadEffect(EFFECT_FILE);  //去除音效
		break;
		// add bakcground music volume
	case 10:
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() + 0.1f);//增加音量
		break;
	case 11:
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() - 0.1f);//降低音量
		break;
	case 12:
		SimpleAudioEngine::getInstance()->setEffectsVolume(SimpleAudioEngine::getInstance()->getEffectsVolume() + 0.1f);//增加音量
		break;
	case 13:
		SimpleAudioEngine::getInstance()->setEffectsVolume(SimpleAudioEngine::getInstance()->getEffectsVolume() - 0.1f);//降低音量
		break;
	case 14:
		SimpleAudioEngine::getInstance()->pauseEffect(m_nSoundId);//暂停音效
		break;
	case 15:
		SimpleAudioEngine::getInstance()->resumeEffect(m_nSoundId);//恢复音效
		break;
	case 16:
		SimpleAudioEngine::getInstance()->pauseAllEffects();//暂停所有音效
		break;
	case 17:
		SimpleAudioEngine::getInstance()->resumeAllEffects();//恢复所有音效
		break;
	case 18:
		SimpleAudioEngine::getInstance()->stopAllEffects();//停止所有音效
		break;
	case 19:
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE1, true);   //播放
		break;
	case 20:
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE2, true);   //播放
		break;
	default: log("music error");
		break;
	}
}

MusicBox* MusicBox::create()
{
	auto musicBox = new MusicBox();
	musicBox->autorelease();
	musicBox->init();
	return musicBox;
}

MusicBox * MusicBox::createWithMusicFlag(int flag)
{
	auto musicBox = new MusicBox();
	musicBox->autorelease();
	musicBox->init();
	musicBox->musicFlagListener(flag);
	return musicBox;
}

