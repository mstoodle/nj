/*******************************************************************************
 * Copyright (c) 2000, 2016 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at http://eclipse.org/legal/epl-2.0
 * or the Apache License, Version 2.0 which accompanies this distribution
 * and is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception [1] and GNU General Public
 * License, version 2 with the OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#ifndef NODEUNIONS_INCL
#define NODEUNIONS_INCL

#include <stddef.h>          // for size_t
#include "il/NodeUtils.hpp"  // for CaseInfo, GlobalRegisterInfo, etc

/*
 * This file defines the unions picked up by TR::Node
 */

struct UnionedWithChildren
   {
   /*
    * To avoid bloating TR_Node, this struct should declare no
    * members outside the below union.
    *
    * Be very careful when adding members as well.
    * It must be ensured that whatever added is exclusive of not only
    * the members in this union, but also the members of the
    * TR::Node child union
    */

   union
      {
#ifdef SUPPORT_DFP
      // Used to hold long double constatants
      uint32_t                _constData[4];
#endif

      GlobalRegisterInfo                _globalRegisterInfo;

      // Offset to WCode literal pool for constants > 8 bytes
      size_t                  _offset;

      ChildUnionMembers::RelocationInfo _relocationInfo;
      ChildUnionMembers::CaseInfo       _caseInfo;
      ChildUnionMembers::MonitorInfo    _monitorInfo;
      };

   };
#endif