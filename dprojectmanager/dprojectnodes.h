#ifndef DPROJECTNODE_H
#define DPROJECTNODE_H

#include <projectexplorer/projectnodes.h>

#include <QStringList>
#include <QHash>
#include <QSet>

namespace Core
{
class IDocument;
}

namespace DProjectManager {
namespace Internal {

class DProject;

class DProjectNode : public ProjectExplorer::ProjectNode
{
public:
 DProjectNode(DProject *project, Core::IDocument *projectFile);

 Core::IDocument *projectFile() const;
 QString projectFilePath() const;

 bool hasBuildTargets() const;

 QList<ProjectExplorer::ProjectNode::ProjectAction> supportedActions(Node *node) const;

 bool canAddSubProject(const QString &proFilePath) const;

 bool addSubProjects(const QStringList &proFilePaths);
 bool removeSubProjects(const QStringList &proFilePaths);

 bool addFiles(const QStringList &filePaths, QStringList *notAdded = 0);
 bool removeFiles(const QStringList &filePaths, QStringList *notRemoved = 0);
 bool deleteFiles(const QStringList &filePaths);
 bool renameFile(const QString &filePath, const QString &newFilePath);

 QList<ProjectExplorer::RunConfiguration *> runConfigurationsFor(Node *node);

 void refresh(QSet<QString> oldFileList = QSet<QString>());

private:
 typedef QHash<QString, FolderNode *> FolderByName;
 FolderNode *createFolderByName(const QStringList &components, int end);
 FolderNode *findFolderByName(const QStringList &components, int end);
 void removeEmptySubFolders(FolderNode *gparent, FolderNode *parent);

private:
 DProject *m_project;
 Core::IDocument *m_projectFile;
};

} // namespace Internal
} // namespace DProjectManager

#endif // DPROJECTNODE_H