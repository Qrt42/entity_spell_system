/*
Copyright (c) 2019-2020 Péter Magyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef LOOT_DATA_CONTAINER_H
#define LOOT_DATA_CONTAINER_H

#include "core/vector.h"
#include "loot_data_base.h"

class LootDataContainter : public LootDataBase {
	GDCLASS(LootDataContainter, LootDataBase);

public:
	int get_num_entries() const;

	Ref<LootDataBase> get_entry(const int index) const;
	void set_entry(const int index, const Ref<LootDataBase> ldb);

	void _get_loot(Array into);

	Vector<Variant> get_entries();
	void set_entries(const Vector<Variant> &auras);

	LootDataContainter();
	~LootDataContainter();

protected:
	static void _bind_methods();

private:
	Vector<Ref<LootDataBase> > _entries;
};

#endif