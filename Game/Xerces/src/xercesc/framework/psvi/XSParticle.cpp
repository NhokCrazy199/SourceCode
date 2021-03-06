/*
 * Copyright 2003,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: XSParticle.cpp 191054 2005-06-17 02:56:35Z jberry $
 */

#include <xercesc/framework/psvi/XSParticle.hpp>
#include <xercesc/framework/psvi/XSElementDeclaration.hpp>
#include <xercesc/framework/psvi/XSModelGroup.hpp>
#include <xercesc/framework/psvi/XSWildcard.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  XSParticle: Constructors and Destructor
// ---------------------------------------------------------------------------
XSParticle::XSParticle(TERM_TYPE            termType,
                       XSModel* const       xsModel,
                       XSObject* const      particleTerm,
                       int                  minOccurs,
                       int                  maxOccurs,
                       MemoryManager* const manager)
    : XSObject(XSConstants::PARTICLE, xsModel, manager)
    , fTermType(termType)
    , fMinOccurs(minOccurs)
    , fMaxOccurs(maxOccurs)
    , fTerm(particleTerm)
{
}

XSParticle::~XSParticle()
{
    if (fTerm && (fTermType == TERM_MODELGROUP))
        delete ((XSModelGroup*) fTerm);
}

// ---------------------------------------------------------------------------
//  XSParticle: methods
// ---------------------------------------------------------------------------
XSElementDeclaration *XSParticle::getElementTerm()
{
    if (fTermType == TERM_ELEMENT)
        return (XSElementDeclaration*) fTerm;

    return 0;
}

XSModelGroup *XSParticle::getModelGroupTerm()
{
    if (fTermType == TERM_MODELGROUP)
        return (XSModelGroup*) fTerm;

    return 0;
}

XSWildcard *XSParticle::getWildcardTerm()
{
    if (fTermType == TERM_WILDCARD)
        return (XSWildcard*) fTerm;

    return 0;
}

XERCES_CPP_NAMESPACE_END


