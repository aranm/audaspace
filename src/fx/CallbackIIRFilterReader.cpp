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

#include "CallbackIIRFilterReader.h"

AUD_NAMESPACE_BEGIN

CallbackIIRFilterReader::CallbackIIRFilterReader(std::shared_ptr<IReader> reader,
														 int in, int out,
														 doFilterIIR doFilter,
														 endFilterIIR endFilter,
														 void* data) :
	BaseIIRFilterReader(reader, in, out),
	m_filter(doFilter), m_endFilter(endFilter), m_data(data)
{
}

CallbackIIRFilterReader::~CallbackIIRFilterReader()
{
	if(m_endFilter)
		m_endFilter(m_data);
}

sample_t CallbackIIRFilterReader::filter()
{
	return m_filter(this, m_data);
}

AUD_NAMESPACE_END
