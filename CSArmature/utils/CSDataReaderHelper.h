/*
 * Copyright (c) 2012 Chukong Technologies, Inc.
 *
 * http://www.cocostudio.com
 * http://tools.cocoachina.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef COCOSTUDIO_CSDATAREADERHELPER_H
#define COCOSTUDIO_CSDATAREADERHELPER_H

#include "cocos2d.h"
#include "CSConstValue.h"
#include "CSDisplayData.h"
#include "CSBoneData.h"
#include "CSAnimationData.h"
#include "CSMovementBoneData.h"
#include "CSMovementFrameData.h"
#include "CSMovementData.h"
#include "CSArmatureData.h"
#include "CSTextureData.h"
#include "CSArmature.h"
#include "CSContourData.h"
#include "CSContentJsonDictionary.h"

using namespace cocos2d;

class TiXmlElement;

namespace cs {


class CS_EXTERN DataReaderHelper
{
    
public:
    
    static void addDataFromFile(const char *_filePath);
public:
    /**
	 *	@brief	Scale the position data, used for multiresolution adapter
     *          It won't effect the data already read.
     *          
     */
    static void setPositionReadScale(float scale);
    static float getPositionReadScale();
    
    ////////////////////////////////////////////////////////////////////////
    ////                                                                ////
    ////                 Decode Data From XML                           ////
    ////                                                                ////
    ////////////////////////////////////////////////////////////////////////
    
    
	/**
	 *	@brief	Translate XML export from Dragon Bone flash tool to datas, and save them.
	 *          When you add a new xml, the data already saved will be keeped.
     *
     *	@param 	_xmlPath path of xml file
     */
    static void addDataFromXML(const char *_xmlPath);
    
    /**
	 *	@brief	Translate XML export from Dragon Bone flash tool to datas, and save them.
	 *          When you add a new xml, the data already saved will be keeped.
     *
     *	@param 	_xmlPath path of pak file
     */
    static void addDataFromXMLPak(const char *_xmlPakPath);
    
    /**
	 *	@brief	Translate XML export from Dragon Bone flash tool to datas, and save them.
	 *          When you add a new xml, the data already saved will be keeped.
     *
     *	@param 	_xmlPath the cache of the xml
     */
    static void addDataFromCache(const char *_pFileContent);
    
    /**
	 *	@brief	Just decode the TexutreData info in the xml, used for other texture info
     *
     *	@param 	_xmlPath path of xml file
     */
    static void addTextureDataFromXML(const char *_xmlPath);
    
    
    
    /**
	 *	@brief	decode Armature Datas from xml export from Dragon Bone flash tool
     */
	static ArmatureData *decodeArmature(TiXmlElement *_armatureXML);
	static BoneData *decodeBone(TiXmlElement *_boneXML, TiXmlElement *_parentXML);
	static DisplayData *decodeBoneDisplay(TiXmlElement *_displayXML);
    
    
	/**
	 *	@brief	decode Animation Datas from xml export from Dragon Bone flash tool
     */
	static AnimationData *decodeAnimation(TiXmlElement *_animationXML);
	static MovementData *decodeMovement(TiXmlElement *_movementXML, ArmatureData *_armatureData);
	static MovementBoneData *decodeMovementBone(TiXmlElement* _movBoneXml, TiXmlElement* _parentXml, BoneData *_boneData);
	static FrameData *decodeFrame(TiXmlElement* _frameXML, TiXmlElement* _parentFrameXml, BoneData *_boneData);
    
	
    /**
	 *	@brief	decode Texture Datas from xml export from Dragon Bone flash tool
     */
	static TextureData *decodeTexture(TiXmlElement *_textureXML);
    
    /**
	 *	@brief	decode Contour Datas from xml export from Dragon Bone flash tool
     */
    static ContourData *decodeContour(TiXmlElement *_contourXML);
    
public:
    
    ////////////////////////////////////////////////////////////////////////
    ////                                                                ////
    ////                 Decode Data From JSON                          ////
    ////                                                                ////
    ////////////////////////////////////////////////////////////////////////
    
    static void readConfigJson(const char *_filePath);
    static void saveConfigToJson(const char *_filePath, const char *_json, int _length);
    
    
    static void addDataFromJson(const char *_filePath);
    
    static void addArmatureDataFromJson(const char *_filePath);
    static void addAnimationDataFromJson(const char *_filePath);
    static void addTextureDataFromJson(const char *_filePath);
    

	static bool saveArmatureDataToJson(const char *_filePath, ArmatureData *_armatureData);
	static bool saveAnimationDataToJson(const char *_filePath, AnimationData *_animationData);
	static bool saveTextureDataToJson(const char *_filePath, TextureData *_textureData);


	static void clearJson();
	static void addArmatureDataToJsonList(ArmatureData *_armatureData);
	static void addAnimationDataToJsonList(AnimationData *_animationData);
	static void addTextureDataToJsonList(TextureData *_textureData);

	static void addAllTextureDataToJsonList();
	static void addAllArmatureDataToJsonList();
	static void addAllAnimationDataToJsonList();

	static std::string getExportJson();


public:
	static std::string convertFlashToSP(const char *fileName);
private:
    
    //! a std::vector save the xml file already added
    static std::vector<std::string> m_arrXMLFileList;
    
    static CSJsonDictionary *m_pJson;
    
    static float m_fPositionReadScale;
};

}

#endif