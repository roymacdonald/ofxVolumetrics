#include "ofxTexture3d.h"
#include "ofTexture.cpp"
template< typename T>
ofxTexture3d<T>::ofxTexture3d()
{
    //ctor
}
template< typename T>
ofxTexture3d<T>::~ofxTexture3d()
{
    release(texData.textureID);
}
template< typename T>
void ofxTexture3d<T>::allocate(int w, int h, int d, int internalGlDataType)
{
    texData.tex_w = w;
    texData.tex_h = h;
    texData.tex_d = d;
    texData.tex_t = w;
    texData.tex_u = h;
    texData.tex_v = d;
    texData.textureTarget = GL_TEXTURE_3D;

    texData.glInternalFormat = internalGlDataType;
    // get the glType (format) and pixelType (type) corresponding to the glTypeInteral (internalFormat)
    texData.glType = ofGetGLFormatFromInternal(texData.glInternalFormat);
    texData.pixelType = ofGetGlTypeFromInternal(texData.glInternalFormat);
    
    cout << "ofxTexture3d glInternalFormat: " << ofGetGlInternalFormatName(internalGlDataType) << endl;
    cout << "ofxTexture3d glType: " << ofGetGlInternalFormatName(texData.glType) << endl;
    cout << "ofxTexture3d pixelType: " << ofGetBytesPerChannelFromGLType(texData.pixelType) << endl;
    // attempt to free the previous bound texture, if we can:
    clear();

    glGenTextures(1, (GLuint *)&texData.textureID);
    retain(texData.textureID);
    glEnable(texData.textureTarget);
    glBindTexture(texData.textureTarget, (GLuint)texData.textureID);

    glTexImage3D(texData.textureTarget, 0, texData.glInternalFormat, (GLint)texData.tex_w, (GLint)texData.tex_h, (GLint)texData.tex_d, 0, texData.glType, texData.pixelType, 0);

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);//GL_REPEAT);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);//GL_REPEAT);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);//GL_REPEAT);

    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glDisable(texData.textureTarget);

    texData.width = w;
    texData.height = h;
    texData.depth = d;
    texData.bFlipTexture = false;
    texData.bAllocated = true;
}
template< typename T>
void ofxTexture3d<T>::loadData(T * data, int w, int h, int d, int xOffset, int yOffset, int zOffset){
//    if(glFormat!=texData.glType)
//    {
//        ofLogError() << "ofxTexture3d<T>::loadData() failed to upload format " <<  ofGetGlInternalFormatName(glFormat) << " data to " << ofGetGlInternalFormatName(texData.glType) << " texture" <<endl;
//        return;
//    }

    if(w > texData.tex_w || h > texData.tex_h || d > texData.tex_d)
    {
        ofLogError() << "ofxTexture3d<T>::loadData() failed to upload " <<  w << "x" << h << "x" << d << " data to " << texData.tex_w << "x" << texData.tex_h << "x" << texData.tex_d << " texture";
        return;
    }


    ofSetPixelStoreiAlignment(GL_UNPACK_ALIGNMENT,w, ofGetBytesPerChannelFromGLType(texData.pixelType), ofGetNumChannelsFromGLFormat(texData.glType));

    glEnable(texData.textureTarget);
    glBindTexture(texData.textureTarget, (GLuint) texData.textureID);
    glTexSubImage3D(texData.textureTarget, 0, xOffset, yOffset, zOffset, w, h, d, texData.glType, texData.pixelType, data);
    glDisable(texData.textureTarget);

}
template< typename T>
void ofxTexture3d<T>::clear()
{
    release(texData.textureID);
    texData.textureID  = 0;
    texData.bAllocated = false;
}
template< typename T>
void ofxTexture3d<T>::bind()
{
    //we could check if it has been allocated - but we don't do that in draw()
    glEnable(texData.textureTarget);
    glBindTexture( texData.textureTarget, (GLuint)texData.textureID);
}

//----------------------------------------------------------
template< typename T>
void ofxTexture3d<T>::unbind()
{
    glDisable(texData.textureTarget);
}
template< typename T>
ofxTextureData3d ofxTexture3d<T>::getTextureData()
{
    if(!texData.bAllocated)
    {
        ofLog(OF_LOG_ERROR, "getTextureData() - texture has not been allocated");
    }

    return texData;
}
template class ofxTexture3d<unsigned char>;
template class ofxTexture3d<unsigned short>;
template class ofxTexture3d<int>;
template class ofxTexture3d<float>;
