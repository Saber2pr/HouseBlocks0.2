/*******************************************************************************************************************************/
//By Prpr_Saber
//2018��7��21��13:18:41

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

	////ʾ����ͼƬ��Ϊrun01, run02, run03... run12, ��Ҫ����20
	//ʮλ����run��+ ��%02d���� ��50�� ��42�� ֡��12�ţ� ֡��0.05f��50���룬 ָ��������ָ��this��
	static Sprite* getSpriteAction(char* s, float width, float height, int n, float fps, Sprite* p);

	//plist��png��֡����֡��(0.05f����
	//*png��ʽ��photo01.png��,���ǰ�����Ʋ��䡣
	//then : runAction(RepeatForever::create())
	static ActionInterval* getSpriteAction(std::string plist, std::string png, int n, float fps);

};
#endif

