#ifndef REDOHANDLER_H
#define REDOHANDLER_H

#include "qheaders.h"

class ThemeData;

class RedoHandler
{
public:
    RedoHandler();
    ~RedoHandler();
    void pushFileSnapshot(ThemeData* fileContent);
    ThemeData* undo();
    ThemeData* redo();

private:
    std::deque<ThemeData*> m_redoStack;
    size_t m_redoStackSize = 0;
    std::deque<ThemeData*> m_undoStack;
    size_t m_undoStackSize = 0;

};

#endif // REDOHANDLER_H
