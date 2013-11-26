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

#include "IReader.h"
#include "Buffer.h"

#include <memory>

AUD_NAMESPACE_BEGIN

/**
 * This reader plays two readers sequently.
 */
class DoubleReader : public IReader
{
private:
	/**
	 * The first reader.
	 */
	std::shared_ptr<IReader> m_reader1;

	/**
	 * The second reader.
	 */
	std::shared_ptr<IReader> m_reader2;

	/**
	 * Whether we've reached the end of the first reader.
	 */
	bool m_finished1;

	// hide copy constructor and operator=
	DoubleReader(const DoubleReader&);
	DoubleReader& operator=(const DoubleReader&);

public:
	/**
	 * Creates a new double reader.
	 * \param reader1 The first reader to read from.
	 * \param reader2 The second reader to read from.
	 */
	DoubleReader(std::shared_ptr<IReader> reader1, std::shared_ptr<IReader> reader2);

	/**
	 * Destroys the reader.
	 */
	virtual ~DoubleReader();

	virtual bool isSeekable() const;
	virtual void seek(int position);
	virtual int getLength() const;
	virtual int getPosition() const;
	virtual Specs getSpecs() const;
	virtual void read(int& length, bool& eos, sample_t* buffer);
};

AUD_NAMESPACE_END
