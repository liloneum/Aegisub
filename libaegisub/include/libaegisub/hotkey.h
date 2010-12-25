// Copyright (c) 2010, Amar Takhar <verm@aegisub.org>
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

/// @file hotkey.h
/// @brief Hotkey handler
/// @ingroup hotkey menu event window

#include "config.h"

#ifndef LAGI_PRE
#include <math.h>

#include <memory>
#endif

#include <libaegisub/cajun/elements.h>


namespace agi {
	namespace hotkey {

class Hotkey;
extern Hotkey *hotkey;

typedef std::vector<std::string> ComboMap;

class Combo {
friend class Hotkey;

public:
	std::string Str();
	std::string StrMenu();
	ComboMap Get();
	std::string CmdName() { return cmd_name; }
	Combo(std::string ctx, std::string cmd): cmd_name(cmd), context(ctx) {}
	std::string Context() { return context; }
	void Enable(bool e) { enable = e; }
	~Combo() {}
private:
	ComboMap key_map;
	std::string cmd_name;
	std::string context;
	bool enable;

	void KeyInsert(std::string key) { key_map.push_back(key); }
};


class Hotkey {
public:
	Hotkey(const std::string &default_config);
	~Hotkey();
	void Scan(std::string context, std::string str);

private:
	typedef std::multimap<std::string, Combo*> HotkeyMap;
	typedef std::pair<std::string, Combo*> HotkeyMapPair;
	HotkeyMap map;

	void BuildHotkey(std::string context, const ::json::Object& object);
	void ComboInsert(Combo *combo);
};

	} // namespace hotkey
} // namespace agi