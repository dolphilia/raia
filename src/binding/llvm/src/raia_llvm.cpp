#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h> // この行を追加
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>

using namespace llvm;

int main() {
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();

    LLVMContext context;
    IRBuilder<> builder(context);
    std::unique_ptr<Module> module = std::make_unique<Module>("my_module", context);

    FunctionType *funcType = FunctionType::get(builder.getInt32Ty(), {builder.getInt32Ty(), builder.getInt32Ty(), builder.getInt32Ty()}, false);
    Function *function = Function::Create(funcType, Function::ExternalLinkage, "f", module.get());

    auto args = function->arg_begin();
    Value *x = args++;
    x->setName("x");
    Value *y = args++;
    y->setName("y");
    Value *z = args++;
    z->setName("z");

    BasicBlock *entry = BasicBlock::Create(context, "entry", function);
    builder.SetInsertPoint(entry);

    Value *counter = builder.CreateAlloca(builder.getInt32Ty(), nullptr, "counter");
    Value *result = builder.CreateAlloca(builder.getInt32Ty(), nullptr, "result");
    builder.CreateStore(x, result);
    builder.CreateStore(builder.getInt32(0), counter);

    BasicBlock *loopStart = BasicBlock::Create(context, "loop.start", function);
    builder.CreateBr(loopStart);

    builder.SetInsertPoint(loopStart);
    Value *currentCounter = builder.CreateLoad(builder.getInt32Ty(), counter, "current.counter");
    Value *currentResult = builder.CreateLoad(builder.getInt32Ty(), result, "current.result");

    BasicBlock *loopEnd = BasicBlock::Create(context, "loop.end", function);
    BasicBlock *afterLoop = BasicBlock::Create(context, "after.loop", function);
    Value *endCondition = builder.CreateICmpEQ(currentCounter, z, "end.condition");
    builder.CreateCondBr(endCondition, afterLoop, loopEnd);

    builder.SetInsertPoint(loopEnd);
    Value *updatedResult = builder.CreateAdd(currentResult, y, "updated.result");
    Value *updatedCounter = builder.CreateAdd(currentCounter, builder.getInt32(1), "updated.counter");
    builder.CreateStore(updatedResult, result);
    builder.CreateStore(updatedCounter, counter);
    builder.CreateBr(loopStart);

    builder.SetInsertPoint(afterLoop);
    Value *finalResult = builder.CreateLoad(builder.getInt32Ty(), result, "final.result");
    builder.CreateRet(finalResult);

    std::string errStr;
    ExecutionEngine *ee = EngineBuilder(std::move(module))
            .setErrorStr(&errStr)
            .create();
    if (!ee) {
        errs() << "Failed to create ExecutionEngine: " << errStr << "\n";
        return 1;
    }

    // 関数のアドレスを取得し、関数ポインタとしてキャスト
    auto funcAddr = ee->getFunctionAddress("f");
    if (!funcAddr) {
        errs() << "Failed to get function address\n";
        return 1;
    }

    // 関数ポインタ型にキャスト
    int (*FP)(int, int, int) = (int (*)(int, int, int))funcAddr;

    // 関数を実行
    int _result = FP(0, 1, 10);
    outs() << "Result of f(0, 1, 10): " << _result << "\n";

    return 0;
}
