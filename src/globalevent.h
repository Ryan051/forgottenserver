/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2015  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef FS_GLOBALEVENT_H_B3FB9B848EA3474B9AFC326873947E3C
#define FS_GLOBALEVENT_H_B3FB9B848EA3474B9AFC326873947E3C
#include "baseevents.h"

#include "const.h"

enum GlobalEvent_t {
	GLOBALEVENT_NONE,
	GLOBALEVENT_TIMER,

	GLOBALEVENT_STARTUP,
	GLOBALEVENT_SHUTDOWN,
	GLOBALEVENT_RECORD,
	GLOBALEVENT_RAID,
};

class GlobalEvent;
typedef std::map<std::string, GlobalEvent*> GlobalEventMap;

class GlobalEvents final : public BaseEvents
{
	public:
		GlobalEvents();
		~GlobalEvents();

		// non-copyable
		GlobalEvents(const GlobalEvents&) = delete;
		GlobalEvents& operator=(const GlobalEvents&) = delete;

		void startup() const;

		void raid();
		void timer();
		void think();
		void execute(GlobalEvent_t type) const;

		GlobalEventMap getEventMap(GlobalEvent_t type);
		static void clearMap(GlobalEventMap& map);

	protected:
		std::string getScriptBaseName() const final {
			return "globalevents";
		}
		void clear() final;

		Event* getEvent(const std::string& nodeName) final;
		bool registerEvent(Event* event, const pugi::xml_node& node) final;

		LuaScriptInterface& getScriptInterface() final {
			return m_scriptInterface;
		}
		LuaScriptInterface m_scriptInterface;

		GlobalEventMap thinkMap, serverMap, timerMap, raidMap;
		int32_t thinkEventId, timerEventId, raidEventId;
};

class GlobalEvent final : public Event
{
	public:
		explicit GlobalEvent(LuaScriptInterface* _interface);

		bool configureEvent(const pugi::xml_node& node) final;

		bool executeRecord(uint32_t current, uint32_t old);
		bool executeEvent();

		GlobalEvent_t getEventType() const {
			return m_eventType;
		}
		std::string getName() const {
			return m_name;
		}

		uint32_t getInterval() const {
			return m_interval;
		}

		int64_t getNextExecution() const {
			return m_nextExecution;
		}
		void setNextExecution(int64_t time) {
			m_nextExecution = time;
		}

	protected:
		GlobalEvent_t m_eventType;

		std::string getScriptEventName() const final;

		std::string m_name;
		int64_t m_nextExecution;
		uint32_t m_interval;
};

#endif
