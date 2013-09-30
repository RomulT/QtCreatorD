#ifndef DMAKESTEP_H
#define DMAKESTEP_H

#include <projectexplorer/abstractprocessstep.h>

QT_BEGIN_NAMESPACE
class QListWidgetItem;
QT_END_NAMESPACE

namespace DProjectManager {
namespace Internal {

class DMakeStepConfigWidget;
class DMakeStepFactory;
namespace Ui { class DMakeStep; }

enum TargetType
{
 Executable = 0,
 StaticLibrary = 1,
 SharedLibrary = 2
};

class DMakeStep : public ProjectExplorer::AbstractProcessStep
{
 Q_OBJECT

 friend class DMakeStepConfigWidget;
 friend class DMakeStepFactory;

public:
 DMakeStep(ProjectExplorer::BuildStepList *parent);
 ~DMakeStep();

 bool init();
 void run(QFutureInterface<bool> &fi);

 ProjectExplorer::BuildStepConfigWidget *createConfigWidget();
 bool immutable() const;
 QString allArguments() const;
 QString makeCommand(const Utils::Environment &environment) const;

 QVariantMap toMap() const;
	bool fromMap(const QVariantMap &map);

 QString outFileName() const;
 QString targetDirName() const { return m_targetDirName; }
	void setMakeArguments(const QString val) { m_makeArguments = val; }

protected:
 DMakeStep(ProjectExplorer::BuildStepList *parent, DMakeStep *bs);
 DMakeStep(ProjectExplorer::BuildStepList *parent, const Core::Id id);

private:
 void ctor();

 TargetType m_targetType;
 QString m_makeArguments;
 QString m_makeCommand;
 QString m_targetName;
 QString m_targetDirName;
 QString m_objDirName;
 QList<ProjectExplorer::Task> m_tasks;
};

class DMakeStepConfigWidget : public ProjectExplorer::BuildStepConfigWidget
{
 Q_OBJECT

public:
 DMakeStepConfigWidget(DMakeStep *makeStep);
 ~DMakeStepConfigWidget();
 QString displayName() const;
 QString summaryText() const;

private slots:
 void targetTypeComboBoxSelectItem(int index);
 void makeLineEditTextEdited();
 void makeArgumentsLineEditTextEdited();
 void targetNameLineEditTextEdited();
 void targetDirNameLineEditTextEdited();
 void objDirLineEditTextEdited();
 void updateMakeOverrrideLabel();
 void updateDetails();

private:
 Ui::DMakeStep *m_ui;
 DMakeStep *m_makeStep;
 QString m_summaryText;
};

class DMakeStepFactory : public ProjectExplorer::IBuildStepFactory
{
 Q_OBJECT

public:
 explicit DMakeStepFactory(QObject *parent = 0);

 bool canCreate(ProjectExplorer::BuildStepList *parent, const Core::Id id) const;
 ProjectExplorer::BuildStep *create(ProjectExplorer::BuildStepList *parent, const Core::Id id);
 bool canClone(ProjectExplorer::BuildStepList *parent,
               ProjectExplorer::BuildStep *source) const;
 ProjectExplorer::BuildStep *clone(ProjectExplorer::BuildStepList *parent,
                                   ProjectExplorer::BuildStep *source);
 bool canRestore(ProjectExplorer::BuildStepList *parent, const QVariantMap &map) const;
 ProjectExplorer::BuildStep *restore(ProjectExplorer::BuildStepList *parent,
                                     const QVariantMap &map);

 QList<Core::Id> availableCreationIds(ProjectExplorer::BuildStepList *bc) const;
 QString displayNameForId(const Core::Id id) const;
};

} // namespace Internal
} // namespace DProjectManager

#endif // DMAKESTEP_H
