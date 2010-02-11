//-----------------------------------------------------------------------------
//
//	Association.h
//
//	Implementation of the Z-Wave COMMAND_CLASS_ASSOCIATION
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

#ifndef _Association_H
#define _Association_H

#include <vector>
#include "CommandClass.h"

namespace OpenZWave
{
	class Association: public CommandClass
	{
	public:
		static CommandClass* Create( uint8 const _nodeId ){ return new Association( _nodeId ); }
		virtual ~Association(){}

		static uint8 const StaticGetCommandClassId(){ return 0x85; }		
		static string const StaticGetCommandClassName(){ return "COMMAND_CLASS_ASSOCIATION"; }

		// From CommandClass
		virtual void RequestState();
		virtual uint8 const GetCommandClassId()const{ return StaticGetCommandClassId(); }		
		virtual string const GetCommandClassName()const{ return StaticGetCommandClassName(); }
		virtual bool HandleMsg( uint8 const* _data, uint32 const _length, uint32 const _instance = 0 );

		void Set( uint8 const _group, uint8 const _nodeId );
		void Remove( uint8 const _group, uint8 const _nodeId );

		vector<uint8> const& GetGroup( uint8 const _groupIdx )const{ return m_groups[_groupIdx-1]; }
		uint8 GetNumGroups()const{ return m_numGroups; }

	private:
		Association( uint8 const _nodeId ): CommandClass( _nodeId ), m_groups( NULL ){}

		uint8			m_numGroups;
		vector<uint8>*	m_groups;
	};

} // namespace OpenZWave

#endif
