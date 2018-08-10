/*******************************************************************************************************************************/
//By Prpr_Saber
//2018年7月21日13:18:41

/******************************************************************************************************************************/

#ifndef _ANIMATETOOL_H_
#define _ANIMATETOOL_H_

#include "cocos2d.h"

USING_NS_CC;
class AnimateTool
{
public:
	AnimateTool();
	~AnimateTool();

	////示例：图片组为run01, run02, run03... run12, 不要超过20
	//十位数则“run”+ “%02d”， 宽50， 高42， 帧数12张， 帧率0.05f即50毫秒， 指向类对象的指针this。
	static Sprite* getSpriteAction(char* s, float width, float height, int n, float fps, Sprite* p);

	//plist、png、帧数、帧率(0.05f）。
	//*png格式“photo01.png”,打包前后名称不变。
	//then : runAction(RepeatForever::create())
	static ActionInterval* getSpriteAction(std::string plist, std::string png, int n, float fps);

};
#endif

