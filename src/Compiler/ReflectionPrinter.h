/*
 * ReflectionPrinter.h
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2017 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef XSC_REFLECTION_PRINTER_H
#define XSC_REFLECTION_PRINTER_H


#include <Xsc/IndentHandler.h>
#include <Xsc/Reflection.h>
#include <ostream>


namespace Xsc
{


class ReflectionPrinter
{

    public:

        ReflectionPrinter(std::ostream& output);

        void PrintReflection(const Reflection::ReflectionData& reflectionData);

    private:

        std::ostream& IndentOut();

        void PrintReflectionObjects(const std::vector<Reflection::BindingSlot>& objects, const char* title);
        void PrintReflectionObjects(const std::vector<std::string>& idents, const char* title);
        void PrintReflectionObjects(const std::map<std::string, Reflection::SamplerState>& samplerStates, const char* title);
        void PrintReflectionAttribute(const Reflection::NumThreads& numThreads, const char* title);

        std::ostream&   output_;
        IndentHandler   indentHandler_;

};


} // /namespace Xsc


#endif



// ================================================================================