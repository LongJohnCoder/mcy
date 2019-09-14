/*
 *  mcy-gui -- Mutation Cover with Yosys GUI
 *
 *  Copyright (C) 2019  Miodrag Milanovic <miodrag@symbioticeda.com>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#ifndef ADDTEST_H
#define ADDTEST_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>

struct TestFile
{    
    TestFile() : reference(false),probe(false) { }
    TestFile(const TestFile &other);
    ~TestFile() { }    
    QString name;
    QString filename;
    QString type;
    bool reference;
    bool probe;
    int percentage;
};
Q_DECLARE_METATYPE(TestFile)

class AddTestDialog : public QDialog
{
    Q_OBJECT

public:
    AddTestDialog(QString path, bool reference, TestFile *data, QWidget *parent = 0);
    QSize sizeHint() const override { return QSize(640, 480); }
    TestFile getItem();

private Q_SLOTS:
    void browseFile();
    void done(int r);
private:
    QString path;
    bool checkName;
    bool reference;
    QLineEdit *name;
    QLineEdit *file;
    QComboBox *testType;
};

#endif // ADDTEST_H