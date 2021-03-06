#ifndef DEDITORCONSTANTS_H
#define DEDITORCONSTANTS_H

#include <QtGlobal>

namespace DEditor {
namespace Constants {

const char D_ACTION_CLEARASSISTCACHE_ID[] = "DEditor.Action";

const char M_CONTEXT[] = "DEditor.ContextMenu";
const char M_TOOLS_D[] = "DEditor.Tools.Menu";

const char M_REFACTORING_MENU_INSERTION_POINT[] = "DEditor.RefactorGroup";

const char C_DEDITOR_ID[] = "DEditor.DTextEditor";
const char C_DEDITOR_DISPLAY_NAME[] = QT_TRANSLATE_NOOP("OpenWith::Editors", "D Editor");

const char D_MIMETYPE_SRC[] = "text/x-dsrc";
const char D_MIMETYPE_HDR[] = "text/x-dhdr";

const char WIZARD_CATEGORY_D[] = "A.D";
const char WIZARD_TR_CATEGORY_D[] = QT_TRANSLATE_NOOP("DEditor", "D");

// Settings
const char INI_SOURCE_ROOT_KEY[]   = "SourceRoot";

} // namespace DEditor
} // namespace Constants

#endif // DEDITORCONSTANTS_H

