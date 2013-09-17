#ifndef DLangEDITOR_CONSTANTS_H
#define DLangEDITOR_CONSTANTS_H

#include <QtGlobal>

namespace DLangEditor {
namespace Constants {

// menus
const char M_CONTEXT[] = "DLang Editor.ContextMenu";
const char M_TOOLS_DLang[] = "DLangEditor.Tools.Menu";

const char M_REFACTORING_MENU_INSERTION_POINT[] = "DLangEditor.RefactorGroup";

const char C_DLANGEDITOR_ID[] = "DLangEditor.DLangTextEditor";
const char C_DLANGEDITOR_DISPLAY_NAME[] = QT_TRANSLATE_NOOP("OpenWith::Editors", "D Editor");

const char DLANG_MIMETYPE[] = "text/x-dsrc";

const char WIZARD_CATEGORY_DLANG[] = "A.D";
const char WIZARD_TR_CATEGORY_DLANG[] = QT_TRANSLATE_NOOP("DLangEditor", "D");

} // namespace Constants
} // namespace DLangEditor

#endif // DLangEDITOR_CONSTANTS_H