// Copyright (c) 2009, Amar Takhar <verm@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// $Id$

/// @file aegisub.h
/// @see aegisub.cpp
/// @ingroup base

#ifndef R_PRECOMP
#include <stdint.h>
#endif

#include <libaegisub/option.h>

/// @class Aegisub
/// @brief Gather Aegisub information from the config file or otherwise.
class Aegisub {
private:
	agi::Options *opt;
public:
	Aegisub();
	~Aegisub();
	const agi::OptionValue* Read(std::string key);
	const std::string GetString(std::string key);
	int64_t GetInt(std::string key);
	bool GetBool(std::string key);
};
