#ifndef NAVIVIEWER_H
#define NAVIVIEWER_H

#include<QWidget>
#include<QSplitter>
#include<QTextEdit>
#include<QTabWidget>
#include<QLayout>
#include<QVBoxLayout>
#include<QPushButton>
#include<QTreeWidget>
#include<QTreeWidgetItem>
#include<QLsit>

#include"IChildViewer.h"
#include"ThumbnailWidget.h"

class TocTreeItem{
public:
    explicit TocTreeItem(QString des, TocTreeItem* parentItem = NULL);
    ~TocTreeItem();
    void appendChild(TocTreeItem *child);
    TocTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QString getDescription(int column) const;
    int row() const;
    TocTreeItem *parentItem();
private:
    Qlist<TocTreeItem*> m_childList;
    TocTreeItem* m_parentItem;
    QString m_dexcription;
};
class TocTreeModel:public QAbstractItemModel{
    Q_OBJECT
public:
    explicit TocTreeModel(QDomDocument* domdoc, QObject *parent = 0);
    ~TocTreeModel();
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    QVatiant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QModelIndex index(int row, int column, const QModelIndex &parent = QmodelIndeex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
private:
    void parserDom(QDomNode* domNode, TocTreeTem *parent);
    TocTreeItem *rootItem;
};

class NaviViewer:public QWidget
{
    Q_OBJECT
public:
    NaviViewer(IChildViewer* childvewer);
private:
    IChildViewer* m_IChildViewer;
private:
    QWidget* m_topNBWidget;
    QTabWidget* m_tabWidget;
    QWidget* m_OutlineWidget;
    QTreeWidget* m_OutlineWidget;
    QVBoxLayout* m_OutlineLayout;
    void ComputerToc(QDomNode* domNode, QTreeWidgetItem* parentWidgetItem);
    QWidget* m_ThumbnailWidget;
    QVBoxLayout* m_ThumbnailLayout;
private slots:
    void sl_btnClicked();
    void outLineTreeClicked(QTreeWidgetItem*, int);
private:
    void InitUI();
    void InitTOC();
    void InitConnect();
};

#endif // NAVIVIEWER_H
