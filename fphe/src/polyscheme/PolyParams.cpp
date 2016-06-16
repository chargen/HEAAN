/*
 * FPHEParams.cpp
 *
 *  Created on: May 15, 2016
 *      Author: kimandrik
 */

#include "PolyParams.h"

#include <sstream>
#include <string>

#include "../utils/PolyRingUtils.h"

PolyParams::PolyParams(long lambda, bool isGauss) : lambda(lambda), isGauss(isGauss) {
	levels = 5;
	stdev = 3;
	tau = 10;
	m = 16384;
	phim = 8192;
	p = 114689;
	Pbits = NumBits(p) * levels;

	RandomBits(B, 3);

	qi = vector<ZZ>();
	Pqi = vector<ZZ>();
	for (int i = 1; i <= levels; ++i) {
		ZZ q = power(p, i);
		qi.push_back(q);
		Pqi.push_back(q << Pbits);
	}

	qL = qi[levels-1];
	Pq = Pqi[levels-1];
}

ZZ& PolyParams::getModulo(long level) {
	return qi[levels - level];
}

PolyParams::~PolyParams() {
	// TODO Auto-generated destructor stub
}

string PolyParams::toString() {
	stringstream ss;

	ss << "Params: ";
	ss << "lambda=";
	ss << lambda;
	ss << ", p=";
	ss << p;
	ss << ", Pbits=";
	ss << Pbits;
	ss << ", qL=";
	ss << qL;
	ss << ", levels=";
	ss << levels;
	ss << ", tau=";
	ss << tau;
	ss << ", m=";
	ss << m;
	ss << ", phim=";
	ss << phim;
	ss << ", isGauss=";
	ss << isGauss;
	ss << ", stdev=";
	ss << stdev;
	ss << ", B=";
	ss << B;
	return ss.str();
}