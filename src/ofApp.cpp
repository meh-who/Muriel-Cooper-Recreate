#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gui.setup();
    gui.add(dis.setup("dis", 75, 0, 150));
    font.load("Tate-Regular.otf",200,true,true,true);
    
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<ConvolutionPass>();
    post.createPass<ConvolutionPass>();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//------draw letters, 2d------
    post.begin();
    ofSetColor(255);
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    string word = "TATE";
    ofRectangle rect = font.getStringBoundingBox(word, 0, 0);
    ofTranslate(-rect.width/2, 0);
    font.drawString(word, 0, 0);
    //std::cout << "rect: " << rect << endl;
    
    ofPopMatrix();
    post.end();
    
    img.grabScreen(0, 0, ofGetWidth(), ofGetHeight()); //screenshot
    
    ofBackground(0);
    gui.draw();

//------draw dots, 3d------
    ofEnableDepthTest();
    cam.enableOrtho();
    
    cam.begin();

    //ofDrawAxis(200);
    for (int j = 0; j < dis; j++){
        for (int k = 0; k <dis; k++){
            float x = ofMap(j, 0, dis, 0, ofGetWidth());
            float y = ofMap(k, 0, dis, 0, ofGetHeight());
            float brightness = img.getColor(x, y).getBrightness();
            float z = ofMap(brightness, 0, 255, 0, 100);
            float r = ofMap(brightness, 0, 255, 1, 5);
            //std::cout << "r: " << r << endl;
            if (brightness != 0){
                ofDrawSphere(x-ofGetWidth()/2, -y+ofGetHeight()/2,z,r);
            }
        }
    }

    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
