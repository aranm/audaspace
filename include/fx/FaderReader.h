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

#include "EffectReader.h"
#include "Buffer.h"

AUD_NAMESPACE_BEGIN

/**
 * This class fades another reader.
 * If the fading type is FADE_IN, everything before the fading start will be
 * silenced, for FADE_OUT that's true for everything after fading ends.
 */
class FaderReader : public EffectReader
{
private:
	/**
	 * The fading type.
	 */
	const FadeType m_type;

	/**
	 * The fading start.
	 */
	const float m_start;

	/**
	 * The fading length.
	 */
	const float m_length;

	// hide copy constructor and operator=
	FaderReader(const FaderReader&);
	FaderReader& operator=(const FaderReader&);

public:
	/**
	 * Creates a new fader reader.
	 * \param type The fading type.
	 * \param start The time where fading should start in seconds.
	 * \param length How long fading should last in seconds.
	 */
	FaderReader(std::shared_ptr<IReader> reader, FadeType type,
					float start,float length);

	virtual void read(int& length, bool& eos, sample_t* buffer);
};

AUD_NAMESPACE_END
