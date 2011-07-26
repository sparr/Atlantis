// START A3HEADER
//
// This source file is part of the Atlantis PBM game program.
// Copyright (C) 1995-1999 Geoff Dunbar
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program, in the file license.txt. If not, write
// to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.
//
// See the Atlantis Project web page for details:
// http://www.prankster.com/project
//
// END A3HEADER

#ifndef QUEST_CLASS
#define QUEST_CLASS

#include "alist.h"
#include "astring.h"
#include "fileio.h"
#include "unit.h"
#include "items.h"

class Quest : public AListElem
{
	public:
		Quest();
		~Quest();

		enum {
			SLAY,
			HARVEST,
			BUILD,
			VISIT,
			DELIVER
		};
		int	type;
		int	target;
		Item	objective;
		int	building;
		int	regionnum;
		AString	regionname;
		AList	rewards;
};

class QuestList : public AList
{
	public:
		int ReadQuests(Ainfile *f);
		void WriteQuests(Aoutfile *f);

		void CheckQuestKillTarget(Unit *u, ItemList *reward);
};

extern QuestList quests;

#endif
