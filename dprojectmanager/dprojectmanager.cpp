#include "dprojectmanagerconstants.h"
#include "dprojectmanager.h"
#include "dproject.h"

#include "deditor/qcdassist.h"

#include <coreplugin/icore.h>
#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projectexplorerconstants.h>
#include <projectexplorer/session.h>
#include <utils/fileutils.h>

#include <QDebug>


namespace DProjectManager {
namespace Internal {

Manager::Manager() { }

QString Manager::mimeType() const
{
 return QLatin1String(Constants::DPROJECT_MIMETYPE);
}

ProjectExplorer::Project *Manager::openProject(const QString &fileName, QString *errorString)
{
 if (!QFileInfo(fileName).isFile())
 {
  if (errorString)
   *errorString = tr("Failed opening project '%1': Project is not a file").arg(fileName);
  return 0;
 }

 DProject* prj = new DProject(this, fileName);

	QString path = prj->buildDirectory().path();
 QcdAssist::sendAddImportToDCD(path);
	QDir dir(path);
	foreach(QString s, prj->includes().split(QLatin1Char(' '), QString::SkipEmptyParts))
	{
		if(s.startsWith(QLatin1String("-I")))
			s = s.remove(0,2);
		if(QDir::isAbsolutePath(s))
			QcdAssist::sendAddImportToDCD(path);
		else
			QcdAssist::sendAddImportToDCD(dir.absoluteFilePath(s));
	}
 return prj;
}

void Manager::registerProject(DProject *project)
{
 m_projects.append(project);
}

void Manager::unregisterProject(DProject *project)
{
 m_projects.removeAll(project);
}

} // namespace Internal
} // namespace DProjectManager
