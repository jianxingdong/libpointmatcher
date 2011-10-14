// kate: replace-tabs off; indent-width 4; indent-mode normal
// vim: ts=4:sw=4:noexpandtab
/*

Copyright (c) 2010--2011,
François Pomerleau and Stephane Magnenat, ASL, ETHZ, Switzerland
You can contact the authors at <f dot pomerleau at gmail dot com> and
<stephane at magnenat dot net>

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ETH-ASL BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef __POINTMATCHER_BIBLIOGRAPHY_H
#define __POINTMATCHER_BIBLIOGRAPHY_H

#include <map>
#include <string>
#include <vector>
#include <stdexcept>

namespace PointMatcherSupport
{
	template <typename K, typename V>
	struct ConvenientMap: public std::map<K, V>
	{
		ConvenientMap():std::map<K, V>() {}
		ConvenientMap(std::initializer_list<typename std::map<K, V>::value_type> list):std::map<K, V>(list) {}
		bool contains(const K& k) const { auto it(this->find(k)); return (it!=this->end()); }
		V get(const K& k) const { auto it(this->find(k)); if (it!=this->end()) return it->second; else throw std::runtime_error("unknown key"); }
	};
	
	typedef std::vector<std::string> StringVector;
	typedef ConvenientMap<std::string, std::string> StringMap;
	typedef ConvenientMap<std::string, StringMap> StringMapMap;
	typedef StringMapMap Bibliography;
	typedef ConvenientMap<std::string, unsigned> BibIndices;
	
	Bibliography bibliography();
	std::string getAndReplaceBibEntries(const std::string& text, BibIndices& indices, StringVector& entries, bool rosWikiAnchor);
}; // PointMatcherSupport

#endif // __POINTMATCHER_BIBLIOGRAPHY_H
