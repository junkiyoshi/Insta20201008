#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofNoFill();
	ofSetCircleResolution(30);

}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	vector<glm::vec2> location_list;
	vector<float> radius_list;
	for (int i = 0; i < 45; i++) {

		auto noise_step = ofRandom(0.001, 0.002);
		auto location = glm::vec2(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * noise_step), 0, 1, -300, 300), ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * noise_step), 0, 1, -300, 300));
		location_list.push_back(location);
		radius_list.push_back(0.f);
	}

	while (true) {

		bool break_flag = true;
		for (int i = 0; i < location_list.size(); i++) {

			bool increment_flag = true;
			for (int k = 0; k < location_list.size(); k++) {

				if (i == k) continue;

				auto distance = glm::distance(location_list[i], location_list[k]);
				if (distance < radius_list[i] + radius_list[k]) {

					increment_flag = false;
				}
			}

			if (increment_flag) {

				radius_list[i] += 1;
				break_flag = false;
			}
		}

		if (break_flag) {

			break;
		}
	}

	for (int i = 0; i < location_list.size(); i++) {

		ofDrawCircle(location_list[i], radius_list[i]);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}