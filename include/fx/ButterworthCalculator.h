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

#include "IDynamicIIRFilterCalculator.h"

AUD_NAMESPACE_BEGIN

class ButterworthCalculator : public IDynamicIIRFilterCalculator
{
private:
	/**
	 * The attack value in seconds.
	 */
	const float m_frequency;

public:
	ButterworthCalculator(float frequency);

	virtual void recalculateCoefficients(SampleRate rate, std::vector<float> &b, std::vector<float> &a);
};

AUD_NAMESPACE_END
