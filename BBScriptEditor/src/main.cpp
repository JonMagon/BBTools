#include "editor.h"
#include <iostream>

static void initializeResources()
{
    Q_INIT_RESOURCE(resources);
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    initializeResources();
    app.setStyle("Fusion");
    app.setApplicationName("BBScriptEditor");
    QIcon applicationIcon;
    for (int size : {16, 24, 32, 48, 64, 128, 256, 512})
    {
        applicationIcon.addFile(QString(":/icons/bbscripteditor-%1.png").arg(size),
                                QSize(size, size));
    }
    app.setWindowIcon(applicationIcon);
    app.setDesktopFileName("bbscripteditor");
    app.setApplicationVersion(SCRIPTS_EDITOR_VERSION);
    app.setOrganizationName("BBTools");
    QCommandLineParser args;
    args.setApplicationDescription("Standalone Beasts & Bumpkins mission script editor");
    args.addHelpOption();
    args.addVersionOption();
    args.addPositionalArgument("files", "Mission/save files to open", "[files…]");
    args.addOption({"snapshot", "Save a window preview and exit", "png"});
    args.addOption({"no-settings", "Do not restore or write window preferences"});
    args.addOption(
        {"game-dir", "Read game archives and artwork from this installation folder", "directory"});
    args.addOption({"archive", "Open missions from a BOX archive", "box"});
    args.process(app);
    try
    {
        bb::Editor window(!args.isSet("no-settings"), args.value("game-dir"));
        if (args.isSet("archive"))
        {
            window.loadCampaign(args.value("archive"));
        }
        for (auto path : args.positionalArguments())
        {
            window.openFile(path);
        }
        window.show();
        for (int i = 0; i < 5; ++i)
        {
            app.processEvents();
        }
        if (args.isSet("snapshot"))
        {
            if (!window.grab().save(args.value("snapshot")))
            {
                throw std::runtime_error("Could not save snapshot");
            }
            return 0;
        }
        return app.exec();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
