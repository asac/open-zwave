//-----------------------------------------------------------------------------
//
//	ThermostatFanMode.h
//
//	Implementation of the Z-Wave COMMAND_CLASS_THERMOSTAT_FAN_MODE
//
//	Copyright (c) 2010 Mal Lansell <openzwave@lansell.org>
//
//	SOFTWARE NOTICE AND LICENSE
//
//	This file is part of OpenZWave.
//
//	OpenZWave is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published
//	by the Free Software Foundation, either version 3 of the License,
//	or (at your option) any later version.
//
//	OpenZWave is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with OpenZWave.  If not, see <http://www.gnu.org/licenses/>.
//
//-----------------------------------------------------------------------------

#ifndef _ThermostatFanMode_H
#define _ThermostatFanMode_H

#include <vector>
#include <string>
#include "CommandClass.h"
#include "ValueList.h"

namespace OpenZWave
{
	class ThermostatFanMode: public CommandClass
	{
	public:
		static CommandClass* Create( uint8 const _nodeId ){ return new ThermostatFanMode( _nodeId ); }
		virtual ~ThermostatFanMode(){}

		static uint8 const StaticGetCommandClassId(){ return 0x44; }		
		static string const StaticGetCommandClassName(){ return "COMMAND_CLASS_THERMOSTAT_FAN_MODE"; }

		// From CommandClass
		virtual void RequestStatic();
		virtual void RequestState();
		virtual uint8 const GetCommandClassId()const{ return StaticGetCommandClassId(); }
		virtual string const GetCommandClassName()const{ return StaticGetCommandClassName(); }
		virtual bool HandleMsg( uint8 const* _data, uint32 const _length, uint32 const _instance = 0 );
		virtual bool SetValue( Value const& _value );

	protected:
		virtual void CreateVars( uint8 const _instance );

	private:
		ThermostatFanMode( uint8 const _nodeId ): CommandClass( _nodeId ){}
		
		vector<ValueList::Item> m_supportedModes;
	};

} // namespace OpenZWave

#endif




