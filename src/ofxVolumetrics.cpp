

#include "ofxVolumetrics.h"
#include "ofMain.h"
#define STRINGIFY( A) #A
//------------------------------------------------------------------------------------------------
template< typename T>
ofxVolumetrics<T>::ofxVolumetrics():bParametersSet(false){
//    quality = ofVec3f(1.0);
//    threshold = 1.0/255.0;
//    density = 1.0;
    volWidth  = 0;
    volHeight = 0;
    volDepth = 0;
    bIsInitialized = false;

    /* Front side */
    volNormals[0] = ofVec3f(0.0, 0.0, 1.0);
    volNormals[1] = ofVec3f(0.0, 0.0, 1.0);
    volNormals[2] = ofVec3f(0.0, 0.0, 1.0);
    volNormals[3] = ofVec3f(0.0, 0.0, 1.0);
    
    volTexCoords[0] = ofVec3f(1.0, 1.0, 1.0);
    volTexCoords[1] = ofVec3f(0.0, 1.0, 1.0);
    volTexCoords[2] = ofVec3f(0.0, 0.0, 1.0);
    volTexCoords[3] = ofVec3f(1.0, 0.0, 1.0);
     /* Right side */
    volNormals[4] = ofVec3f(1.0, 0.0, 0.0);
    volNormals[5] = ofVec3f(1.0, 0.0, 0.0);
    volNormals[6] = ofVec3f(1.0, 0.0, 0.0);
    volNormals[7] = ofVec3f(1.0, 0.0, 0.0);
    
    volTexCoords[4] = ofVec3f(1.0, 1.0, 1.0);
    volTexCoords[5] = ofVec3f(1.0, 0.0, 1.0);
    volTexCoords[6] = ofVec3f(1.0, 0.0, 0.0);
    volTexCoords[7] = ofVec3f(1.0, 1.0, 0.0);
      /* Top side */
    volNormals[8] = ofVec3f(0.0, 1.0, 0.0);
    volNormals[9] = ofVec3f(0.0, 1.0, 0.0);
    volNormals[10] = ofVec3f(0.0, 1.0, 0.0);
    volNormals[11] = ofVec3f(0.0, 1.0, 0.0);
    
    volTexCoords[8] = ofVec3f(1.0, 1.0, 1.0);
    volTexCoords[9] = ofVec3f(1.0, 1.0, 0.0);
    volTexCoords[10] = ofVec3f(0.0, 1.0, 0.0);
    volTexCoords[11] = ofVec3f(0.0, 1.0, 1.0);
    /* Left side */
    volNormals[12] = ofVec3f(-1.0, 0.0, 0.0);
    volNormals[13] = ofVec3f(-1.0, 0.0, 0.0);
    volNormals[14] = ofVec3f(-1.0, 0.0, 0.0);
    volNormals[15] = ofVec3f(-1.0, 0.0, 0.0);
    
    volTexCoords[12] = ofVec3f(0.0, 1.0, 1.0);
    volTexCoords[13] = ofVec3f(0.0, 1.0, 0.0);
    volTexCoords[14] = ofVec3f(0.0, 0.0, 0.0);
    volTexCoords[15] = ofVec3f(0.0, 0.0, 1.0);
    /* Bottom side */
    volNormals[16] = ofVec3f(0.0, -1.0, 0.0);
    volNormals[17] = ofVec3f(0.0, -1.0, 0.0);
    volNormals[18] = ofVec3f(0.0, -1.0, 0.0);
    volNormals[19] = ofVec3f(0.0, -1.0, 0.0);
    
    volTexCoords[16] = ofVec3f(0.0, 0.0, 0.0);
    volTexCoords[17] = ofVec3f(1.0, 0.0, 0.0);
    volTexCoords[18] = ofVec3f(1.0, 0.0, 1.0);
    volTexCoords[19] = ofVec3f(0.0, 0.0, 1.0);
    /* Back side */
    volNormals[20] = ofVec3f(0.0, 0.0, -1.0);
    volNormals[21] = ofVec3f(0.0, 0.0, -1.0);
    volNormals[22] = ofVec3f(0.0, 0.0, -1.0);
    volNormals[23] = ofVec3f(0.0, 0.0, -1.0);
    
    volTexCoords[20] = ofVec3f(1.0, 0.0, 0.0);
    volTexCoords[21] = ofVec3f(0.0, 0.0, 0.0);
    volTexCoords[22] = ofVec3f(0.0, 1.0, 0.0);
    volTexCoords[23] = ofVec3f(1.0, 1.0, 0.0);
    
    /* Front side */
    volVerts[0] = ofVec3f( 1.0,  1.0,  1.0);
    volVerts[1] = ofVec3f( 0.0,  1.0,  1.0);
    volVerts[2] = ofVec3f( 0.0,  0.0,  1.0);
    volVerts[3] = ofVec3f( 1.0,  0.0,  1.0);
    /* Right side */
    volVerts[4] = ofVec3f( 1.0,  1.0,  1.0);
    volVerts[5] = ofVec3f( 1.0,  0.0,  1.0);
    volVerts[6] = ofVec3f( 1.0,  0.0,  0.0);
    volVerts[7] = ofVec3f( 1.0,  1.0,  0.0);
    /* Top side */
    volVerts[8] = ofVec3f( 1.0,  1.0,  1.0);
    volVerts[9] = ofVec3f( 1.0,  1.0,  0.0);
    volVerts[10] = ofVec3f( 0.0,  1.0,  0.0);
    volVerts[11] = ofVec3f( 0.0,  1.0,  1.0);
    /* Left side */
    volVerts[12] = ofVec3f( 0.0,  1.0,  1.0);
    volVerts[13] = ofVec3f( 0.0,  1.0,  0.0);
    volVerts[14] = ofVec3f( 0.0,  0.0,  0.0);
    volVerts[15] = ofVec3f( 0.0,  0.0,  1.0);
    /* Bottom side */
    volVerts[16] = ofVec3f( 0.0,  0.0,  0.0);
    volVerts[17] = ofVec3f( 1.0,  0.0,  0.0);
    volVerts[18] = ofVec3f( 1.0,  0.0,  1.0);
    volVerts[19] = ofVec3f( 0.0,  0.0,  1.0);
    /* Back side */
    volVerts[20] = ofVec3f( 1.0,  0.0,  0.0);
    volVerts[21] = ofVec3f( 0.0,  0.0,  0.0);
    volVerts[22] = ofVec3f( 0.0,  1.0,  0.0);
    volVerts[23] = ofVec3f( 1.0,  1.0,  0.0);

}
//------------------------------------------------------------------------------------------------
template< typename T>
ofxVolumetrics<T>::~ofxVolumetrics(){
    destroy();
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setup(int vol_w, int vol_h, int vol_d, int tex_w, int tex_h, int tex_d, ofVec3f voxelSize, int internalformat, bool usePowerOfTwoTexSize, bool bSetShader){
    if (bSetShader) {
        setShader();
    }

    setParameters();
    
    
    bIsPowerOfTwo = usePowerOfTwoTexSize;

    volWidthPOT = volWidth = vol_w;
    volHeightPOT = volHeight = vol_h;
    volDepthPOT = volDepth = vol_d;

    if(bIsPowerOfTwo){
        volWidthPOT = ofNextPow2(vol_w);
        volHeightPOT = ofNextPow2(vol_h);
        volDepthPOT = ofNextPow2(vol_d);

//        ofLogVerbose() << "ofxVolumetrics<T>::setup(): Using power of two texture size. Requested: " << w << "x" <<h<<"x"<<d<<". Actual: " << volWidthPOT<<"x"<<volHeightPOT<<"x"<<volDepthPOT<<".\n";
    }
    if (bIsInitialized) {

        volumeTexture.clear();
    }
    
    cout<<"ofxVolumetrics<T>::setup  volumeTexture.allocate"<<endl;
    volumeTexture.allocate(tex_w, tex_h, tex_d, internalformat);
    voxelRatio = voxelSize;
    bIsInitialized = true;
    cout << "ofxVolumetrics<T>::setup " << volWidthPOT << ", " << volHeightPOT << ", " << volDepthPOT << endl;
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setParameters(){
    if (!bParametersSet) {
        bParametersSet = true;
        parameters.setName("Volume params");
        parameters.add(quality.set("Quality (q/Q))", {1.0, 1, 1}, {0.001,0.001,0.001}, {1,1,1}));
        parameters.add(threshold.set("Threshold (t/T)", 1.0/255.0, 0, 1));
        parameters.add(density.set("Density (d/D)", 1.0, 0.0, 2.0));
        parameters.add(planeNorm.set("Plane Normal", {0,0,1}, {-1,-1,-1}, {1,1,1}));
        parameters.add(planePos.set("Plane Position", 1, -1,1));
        parameters.add(bCullFace.set("Cull Face", true));
        parameters.add(bLinearNearest.set("Linear/Nearest filter", true));
        bLinearNearest.addListener(this, &ofxVolumetrics<T>::linearNearestChanged);

    }
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setShader(){
    cout << "ofxVolumetrics<T>::setting inline shader" <<endl;
    string vertexShader = STRINGIFY(
                                    varying vec3 cameraPosition;
                                    void main()
                                    {
                                        gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
                                        gl_TexCoord[0] = gl_MultiTexCoord0; //poop
                                        cameraPosition = (gl_ModelViewMatrixInverse * vec4(0.,0.,0.,1.)).xyz;
                                    }); // END VERTEX SHADER STRINGIFY
    
    string fragmentShader = STRINGIFY((#extension GL_ARB_texture_rectangle : enable \n
                                       varying vec3 cameraPosition;
                                       
                                       uniform sampler3D volume_tex;
                                       uniform vec3 vol_d;
                                       uniform vec3 vol_d_pot;
                                       uniform vec2 bg_d;
                                       uniform float zoffset;
                                       uniform float quality;
                                       uniform float threshold;
                                       uniform float density;
                                       
                                       struct Ray {
                                           vec3 Origin;
                                           vec3 Dir;
                                       };
                                       
                                       struct BoundingBox {
                                           vec3 Min;
                                           vec3 Max;
                                       };
                                       
                                       bool IntersectBox(Ray r, BoundingBox box, out float t0, out float t1)
                                       {
                                           vec3 invR = 1.0 / r.Dir;
                                           vec3 tbot = invR * (box.Min-r.Origin);
                                           vec3 ttop = invR * (box.Max-r.Origin);
                                           vec3 tmin = min(ttop, tbot);
                                           vec3 tmax = max(ttop, tbot);
                                           vec2 t = max(tmin.xx, tmin.yz);
                                           t0 = max(t.x, t.y);
                                           t = min(tmax.xx, tmax.yz);
                                           t1 = min(t.x, t.y);
                                           return t0 <= t1;
                                       }
                                       
                                       void main()
                                       {
                                           
                                           vec3 minv = vec3(0.)+1./vol_d_pot;
                                           vec3 maxv = (vol_d/vol_d_pot)-1./vol_d_pot;
                                           vec3 vec;
                                           vec3 vold = (maxv-minv)*vol_d;
                                           float vol_l = length(vold);
                                           
                                           vec4 col_acc = vec4(0,0,0,0);
                                           vec3 zOffsetVec = vec3(0.0,0.0,zoffset/vol_d_pot.z);
                                           vec3 backPos = gl_TexCoord[0].xyz;
                                           vec3 lookVec = normalize(backPos - cameraPosition);
                                           
                                           
                                           Ray eye = Ray( cameraPosition, lookVec);
                                           BoundingBox box = BoundingBox(vec3(0.),vec3(1.));
                                           
                                           float tnear, tfar;
                                           IntersectBox(eye, box, tnear, tfar);
                                           if(tnear < 0.15) tnear = 0.15;
                                           if(tnear > tfar) discard;
                                           
                                           vec3 rayStart = (eye.Origin + eye.Dir * tnear)*(maxv-minv)+minv;//vol_d/vol_d_pot;
                                           vec3 rayStop = (eye.Origin + eye.Dir * tfar)*(maxv-minv)+minv;//vol_d/vol_d_pot;
                                           
                                           vec3 dir = rayStop - rayStart; // starting position of the ray
                                           
                                           vec = rayStart;
                                           float dl = length(dir);
                                           if(dl == clamp(dl,0.,vol_l)) {
                                               int steps = int(floor(length(vold * dir) * quality));
                                               vec3 delta_dir = dir/float(steps);
                                               vec4 color_sample;
                                               float aScale =  density/quality;
                                               
                                               float random = fract(sin(gl_FragCoord.x * 12.9898 + gl_FragCoord.y * 78.233) * 43758.5453);
                                               vec += delta_dir * random;
                                               
                                               //raycast
                                               for(int i = 0; i < steps; i++)
                                               {
                                                   vec3 vecz = vec + zOffsetVec;
                                                   if(vecz.z > maxv.z) vecz.z-=maxv.z;
                                                   color_sample = texture3D(volume_tex, vecz);
                                                   if(color_sample.a > threshold) {
                                                       
                                                       float oneMinusAlpha = 1. - col_acc.a;
                                                       color_sample.a *= aScale;
                                                       col_acc.rgb = mix(col_acc.rgb, color_sample.rgb * color_sample.a, oneMinusAlpha);
                                                       col_acc.a += color_sample.a * oneMinusAlpha;
                                                       col_acc.rgb /= col_acc.a;
                                                       if(col_acc.a >= 1.0) {
                                                           break; // terminate if opacity > 1
                                                       }
                                                   }
                                                   vec += delta_dir;
                                               }
                                           }
                                           // export the rendered color
                                           gl_FragColor = col_acc;
                                           
                                       } )); // END FRAGMENT SHADER STRINGIFY
    
    // For whatever reason, the stringify macro takes the fragment shader code as 2 arguments,
    // wrapping it in () makes it compile, so trim them off
    fragmentShader = fragmentShader.substr(1,fragmentShader.size()-2);
    
    volumeShader.unload();
    volumeShader.setupShaderFromSource(GL_VERTEX_SHADER, vertexShader);
    volumeShader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShader);
    volumeShader.linkProgram();
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::loadShader(string path){
    cout << "ofxVolumetrics<T>::load shader file " << path <<endl;
    volumeShader.unload();
    volumeShader.load(path);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::destroy(){
    volumeShader.unload();
    volumeTexture.clear();

    volWidth = 0;
    volHeight = 0;
    volDepth = 0;
    bIsInitialized = false;
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::updateVolumeData(T * data, int w, int h, int d, int xOffset, int yOffset, int zOffset){
    cout << "ofxVolumetrics<T>::updateVolumeData  " << w << ", " << h << ", " << d << endl;
    volumeTexture.loadData(data, w, h, d, xOffset, yOffset, zOffset);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::drawVolume(float x, float y, float z, float size, float zTexOffset){
    ofVec3f volumeSize = voxelRatio * ofVec3f(volWidth,volHeight,volDepth);
    float maxDim = max(max(volumeSize.x, volumeSize.y), volumeSize.z);
  //  volumeSize = volumeSize * size / maxDim;

    drawVolume(x, y, z, volumeSize.x, volumeSize.y, volumeSize.z, zTexOffset);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setShaderUniforms(){
    volumeShader.setUniformTexture("volume_tex", volumeTexture.getTextureData().textureTarget, volumeTexture.getTextureData().textureID,0);
    volumeShader.setUniform3f("vol_d", (float)volWidth, (float)volHeight, (float)volDepth); //dimensions of the volume texture
    volumeShader.setUniform3f("vol_d_pot", (float)volWidthPOT, (float)volHeightPOT, (float)volDepthPOT); //dimensions of the volume texture power of two

    volumeShader.setUniform1f("zoffset",zTexOffset); // used for animation so that we dont have to upload the entire volume every time
    volumeShader.setUniform1f("quality", quality->z); // 0 ... 1
    volumeShader.setUniform1f("density", density); // 0 ... 1
    volumeShader.setUniform1f("threshold", threshold);//(float)mouseX/(float)ofGetWidth());
    volumeShader.setUniform3fv("plane_n", &planeNorm.get().x);
    volumeShader.setUniform1f("plane_p", planePos);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::drawVolume(float x, float y, float z, float w, float h, float d, float zTexOffset){
    this->zTexOffset = zTexOffset;
    ofPushMatrix();
    ofVec3f cubeSize = ofVec3f(w, h, d);
//*
    GLfloat modl[16];
    glGetFloatv( GL_MODELVIEW_MATRIX, modl);
    ofVec3f scale,t;
    ofQuaternion a,b;
    ofMatrix4x4(modl).decompose(t, a, scale, b);

    GLint cull_mode;
    glGetIntegerv(GL_FRONT_FACE, &cull_mode);
    GLint cull_mode_fbo = (scale.x*scale.y*scale.z) > 0 ? GL_CCW : GL_CW;

    volumeShader.begin();

    ofTranslate(x-cubeSize.x/2, y-cubeSize.y/2, z-cubeSize.z/2);
    ofScale(cubeSize.x,cubeSize.y,cubeSize.z);

    setShaderUniforms();
    
    if(bCullFace){
        glFrontFace(cull_mode_fbo);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
   }
    drawRGBCube();
    if(bCullFace){
        glDisable(GL_CULL_FACE);
        glFrontFace(cull_mode);
    }
    volumeShader.end();
    ofPopMatrix();

}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::drawRGBCube(){
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, sizeof(ofVec3f), volVerts);
    glNormalPointer(GL_FLOAT, sizeof(ofVec3f), volNormals);
    glColorPointer(3,GL_FLOAT, sizeof(ofVec3f), volVerts);
    glTexCoordPointer(3, GL_FLOAT, sizeof(ofVec3f), volTexCoords);

    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setPlaneNormal(const ofVec3f & norm){
    planeNorm.set(norm);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setPlanePos(const float & pos){
    planePos.set(pos);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setXyQuality(float q){
//    float oldQuality = quality->x;
    ofVec3f qua = quality.get();
    qua.x = MAX(q,0.01);
    quality.set(qua);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setZQuality(float q){
    ofVec3f qua = quality.get();
    qua.z = MAX(q,0.01);
    quality.set(qua);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setThreshold(float t){
    threshold = ofClamp(t,0.0,1.0);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setDensity(float d){
    density = MAX(d,0.0);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setRenderSettings(float xyQuality, float zQuality, float dens, float thresh){
    setXyQuality(xyQuality);
    setZQuality(zQuality);
    setDensity(dens);
    setThreshold(thresh);
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::linearNearestChanged(bool & b){
    setVolumeTextureFilterMode((b?GL_LINEAR:GL_NEAREST));
}
//------------------------------------------------------------------------------------------------
template< typename T>
void ofxVolumetrics<T>::setVolumeTextureFilterMode(GLint filterMode) {
    if(filterMode != GL_NEAREST && filterMode != GL_LINEAR) return;

    volumeTexture.bind();
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, filterMode);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, filterMode);
    volumeTexture.unbind();
}
//------------------------------------------------------------------------------------------------
template< typename T>
bool ofxVolumetrics<T>::isInitialized(){
    return bIsInitialized;
}
//------------------------------------------------------------------------------------------------
template< typename T>
int ofxVolumetrics<T>::getVolumeWidth(){
    return volWidth;
}
//------------------------------------------------------------------------------------------------
template< typename T>
int ofxVolumetrics<T>::getVolumeHeight(){
    return volHeight;
}
//------------------------------------------------------------------------------------------------
template< typename T>
int ofxVolumetrics<T>::getVolumeDepth(){
    return volDepth;
}
//------------------------------------------------------------------------------------------------
template< typename T>
ofVec3f ofxVolumetrics<T>::getVolumeSize(){
    return ofVec3f(volWidth, volHeight, volDepth);
}
//------------------------------------------------------------------------------------------------
template< typename T>
ofVec3f ofxVolumetrics<T>::getVolumeSizePOT(){
    return ofVec3f(volWidthPOT, volHeightPOT, volDepthPOT);
}
//------------------------------------------------------------------------------------------------
template< typename T>
float ofxVolumetrics<T>::getXyQuality(){
    return quality->x;
}
//------------------------------------------------------------------------------------------------
template< typename T>
float ofxVolumetrics<T>::getZQuality(){
    return quality->z;
}
//------------------------------------------------------------------------------------------------
template< typename T>
float ofxVolumetrics<T>::getThreshold(){
    return threshold;
}
//------------------------------------------------------------------------------------------------
template< typename T>
float ofxVolumetrics<T>::getDensity(){
    return density;
}
//------------------------------------------------------------------------------------------------
template class ofxVolumetrics<unsigned char>;
template class ofxVolumetrics<unsigned short>;
template class ofxVolumetrics<int>;
template class ofxVolumetrics<float>;