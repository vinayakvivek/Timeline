#include "instrument.h"

Instrument::Instrument() {
      name = "Untitled";
      nameText = NULL;
      nameBox = NULL;
      measureBoxes.resize(0);

      nameBoxWidth = 20;
      nameBoxLength = 100;
}
