#ifndef RAINDROPS_MXUTILS_HPP
#define RAINDROPS_MXUTILS_HPP

#include "Measure.hpp"
#include "Note.hpp"
#include <mx/api/DocumentManager.h>

namespace raindrops::MxUtils
{
    int convertMxPitchDataToMidiKey(mx::api::Step step, int octave, int alter);
    Note createNoteFromMxNote(const mx::api::NoteData& mxNote);
    std::vector<Note> extractNotesFromMxStaff(const mx::api::StaffData& staff);
    Measure convertFromMxMeasure(const mx::api::MeasureData& mxMeasure, int index);
}

#endif //RAINDROPS_MXUTILS_HPP