#pragma once

/*      ofxVolumetrics - render volumetric data on the GPU

 Written by Timothy Scaffidi (http://timothyscaffidi.com)
 Volumetric rendering algorithm adapted from Peter Trier (http://www.daimi.au.dk/~trier/?page_id=98)

*/

#define USE_AUTO_RELOAD_SHADER

#include "ofFbo.h"
#include "ofShader.h"
#include "ofxTexture3d.h"
#ifdef USE_AUTO_RELOAD_SHADER
#include "ofxAutoReloadedShader.h"
#endif
template< typename T>
class ofxVolumetrics
{
public:
    ofxVolumetrics();
    virtual ~ofxVolumetrics();
    //internalformat = GL_RGBA...
    void setup(int vol_w, int vol_h, int vol_d, int tex_w, int tex_h, int tex_d, ofVec3f voxelSize,  int internalformat, bool usePowerOfTwoTexSize=false, bool bSetShader = true);
    void destroy();
    void updateVolumeData(T * data, int w, int h, int d, int xOffset, int yOffset, int zOffset);
    void drawVolume(float x, float y, float z, float size, float zTexOffset);
    void drawVolume(float x, float y, float z, float w, float h, float d, float zTexOffset);

    bool isInitialized();
    int getVolumeWidth();
    int getVolumeHeight();
    int getVolumeDepth();
    ofVec3f getVolumeSize();
    ofVec3f getVolumeSizePOT();

    float getXyQuality();
    float getZQuality();
    float getThreshold();
    float getDensity();
    ofxTexture3d<T>& getTexture(){return volumeTexture;}

    void setXyQuality(float q);
    void setZQuality(float q);
    void setThreshold(float t);
    void setDensity(float d);
    void setRenderSettings(float xyQuality, float zQuality, float dens, float thresh);
    void setVolumeTextureFilterMode(GLint filterMode);
    void loadShader(string path);

    void setPlaneNormal(const ofVec3f & norm);
    void setPlanePos(const float & pos);
    
    ofParameterGroup parameters;
    ofParameter<float>  threshold, density, planePos;
    ofParameter<glm::vec3> planeNorm, quality;
    ofParameter<bool>bCullFace;
    ofParameter<bool>bLinearNearest;
    
protected:
    void setShader();
    void setParameters();

    void drawRGBCube();


    virtual void setShaderUniforms();
#ifdef USE_AUTO_RELOAD_SHADER
    ofxAutoReloadedShader volumeShader;
#else
    ofShader volumeShader;
#endif
private:
    ofxTexture3d<T> volumeTexture;
    ofVec3f volVerts[24];
    ofVec3f volNormals[24];
    ofVec3f volTexCoords[24];
    ofVec3f voxelRatio;
    bool bIsInitialized;
    int volWidth, volHeight, volDepth;
    int volWidthPOT, volHeightPOT, volDepthPOT;
    bool bIsPowerOfTwo;
    


    void linearNearestChanged(bool & b);

    
    bool bParametersSet;
    
    float zTexOffset=0;
    
};
