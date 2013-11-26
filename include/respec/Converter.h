/*******************************************************************************
 * Copyright 2009-2013 Jörg Müller
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

#include "SpecsChanger.h"

AUD_NAMESPACE_BEGIN

/**
 * This factory creates a converter reader that is able to convert from one
 * audio format to another.
 */
class Converter : public SpecsChanger
{
private:
	// hide copy constructor and operator=
	Converter(const Converter&);
	Converter& operator=(const Converter&);

public:
	/**
	 * Creates a new factory.
	 * \param factory The input factory.
	 * \param specs The target specifications.
	 */
	Converter(std::shared_ptr<ISound> factory, DeviceSpecs specs);

	virtual std::shared_ptr<IReader> createReader();
};

AUD_NAMESPACE_END
