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

#include "Converter.h"
#include "ConverterReader.h"

AUD_NAMESPACE_BEGIN

Converter::Converter(std::shared_ptr<ISound> factory,
										   DeviceSpecs specs) :
		SpecsChanger(factory, specs)
{
}

std::shared_ptr<IReader> Converter::createReader()
{
	std::shared_ptr<IReader> reader = getReader();

	if(m_specs.format != FORMAT_FLOAT32)
		reader = std::shared_ptr<IReader>(new ConverterReader(reader, m_specs));

	return reader;
}

AUD_NAMESPACE_END
