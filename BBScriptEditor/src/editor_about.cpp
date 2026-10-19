#include "editor.h"

namespace bb
{
void Editor::showAbout()
{
    auto dialog = new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle("About BBScriptEditor");
    auto layout = new QVBoxLayout(dialog);
    layout->setContentsMargins(20, 20, 20, 16);
    layout->setSpacing(16);

    auto heading = new QHBoxLayout;
    auto icon = new QLabel;
    icon->setPixmap(windowIcon().pixmap(96, 96));
    heading->addWidget(icon);
    auto introduction = new QVBoxLayout;

    auto title = new QLabel("BBScriptEditor");
    auto font = title->font();
    font.setPointSize(font.pointSize() + 6);
    font.setBold(true);
    title->setFont(font);
    introduction->addWidget(title);
    auto description = new QLabel("Beasts & Bumpkins Mission Script Editor");
    description->setWordWrap(true);
    introduction->addWidget(description);
    heading->addLayout(introduction, 1);
    layout->addLayout(heading);

    auto details = new QGroupBox;
    auto fields = new QFormLayout(details);
    fields->setHorizontalSpacing(24);
    fields->setVerticalSpacing(10);
    fields->addRow("Version:", new QLabel(QCoreApplication::applicationVersion()));
    auto author = new QLabel("<a href=\"https://github.com/JonMagon\">Dmitry Sidorov</a>");
    author->setOpenExternalLinks(true);
    fields->addRow("Author:", author);
    auto email = new QLabel("<a href=\"mailto:jonmagon@gmail.com\">jonmagon@gmail.com</a>");
    email->setOpenExternalLinks(true);
    fields->addRow("E-mail:", email);
    layout->addWidget(details);

    auto buttons = new QDialogButtonBox(QDialogButtonBox::Close);
    buttons->setCenterButtons(true);
    connect(buttons, &QDialogButtonBox::rejected, dialog, &QDialog::close);
    layout->addWidget(buttons);
    dialog->setMinimumWidth(420);
    dialog->show();
}
} // namespace bb
