#include "MusicBox.h"



MusicBox::MusicBox()
{
}


MusicBox::~MusicBox()
{
}


bool MusicBox::init()
{
	//��Ч�ļ�
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	#define MUSIC_FILE        "backMusic.mp3"
	#define MUSIC_FILE1        "backMusic1.mp3"
	#define MUSIC_FILE2        "backMusic2.mp3"
	#define EFFECT_FILE        "backMusic.mp3"
	#endif

	//�����ļ�
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
		// �������ֲ���:
	case 0:
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE, true);   //����
		break;
	case 1:
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();  // ֹͣ����
		break;
	case 2:
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();   //��ͣ����
		break;
	case 3:
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();   // �ָ�����
		break;
	case 4:
		SimpleAudioEngine::getInstance()->rewindBackgroundMusic();   //��ͷ���²���
		break;
	case 5:
		if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())    //�жϵ�ǰ�Ƿ񲥷ű�������
		{
			CCLOG("background music is playing");
		}
		else
		{
			CCLOG("background music is not playing");
		}
		break;
		// ��Ч����
	case 6:
	{
		m_nSoundId = SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE); //����
	}  
	break;
	case 7:
	{
		m_nSoundId = SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE, true);
	}
		break;
	case 8:
		SimpleAudioEngine::getInstance()->stopEffect(m_nSoundId);   //ֹͣ����
		break;
	case 9:
		SimpleAudioEngine::getInstance()->unloadEffect(EFFECT_FILE);  //ȥ����Ч
		break;
		// add bakcground music volume
	case 10:
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() + 0.1f);//��������
		break;
	case 11:
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() - 0.1f);//��������
		break;
	case 12:
		SimpleAudioEngine::getInstance()->setEffectsVolume(SimpleAudioEngine::getInstance()->getEffectsVolume() + 0.1f);//��������
		break;
	case 13:
		SimpleAudioEngine::getInstance()->setEffectsVolume(SimpleAudioEngine::getInstance()->getEffectsVolume() - 0.1f);//��������
		break;
	case 14:
		SimpleAudioEngine::getInstance()->pauseEffect(m_nSoundId);//��ͣ��Ч
		break;
	case 15:
		SimpleAudioEngine::getInstance()->resumeEffect(m_nSoundId);//�ָ���Ч
		break;
	case 16:
		SimpleAudioEngine::getInstance()->pauseAllEffects();//��ͣ������Ч
		break;
	case 17:
		SimpleAudioEngine::getInstance()->resumeAllEffects();//�ָ�������Ч
		break;
	case 18:
		SimpleAudioEngine::getInstance()->stopAllEffects();//ֹͣ������Ч
		break;
	case 19:
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE1, true);   //����
		break;
	case 20:
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE2, true);   //����
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

