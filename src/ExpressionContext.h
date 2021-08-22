#pragma once
#include "StaticVariable.h"
#include "VariableUpdater.h"

namespace ffscript {
    class CLamdaProg;
    class Program;
}

namespace xpression {
    class SimpleCompilerSuite;
    class VariableManager;

    class ExpressionContext {
        SimpleCompilerSuite* _pCompilerSuite;
        ffscript::CLamdaProg* _pCustomScript;
        ffscript::Program* _pRawProgram;
        VariableManager* _pVariableManager;
    public:
        ExpressionContext();
        ~ExpressionContext();

        SimpleCompilerSuite* getCompilerSuite() const;
        void setCustomScript(const wchar_t* customScript);
        void startEvaluating();
        void stopEvaluating();
        void addVariable(Variable* pVariable);
        VariableUpdater* getVariableUpdater();
        void setVariableUpdater(VariableUpdater* pVariableUpdater);

        static ExpressionContext* getCurrentContext();
        static void setCurrentContext(ExpressionContext* pContext);
    };
}