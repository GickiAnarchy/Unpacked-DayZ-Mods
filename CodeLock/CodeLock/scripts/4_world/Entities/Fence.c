modded class Fence {
    typename ATTACHMENT_CODE_LOCK = CodeLock;

    override bool CanOpenFence() {
        if (IsCodeLocked()) {
            return false;
        }
        return super.CanOpenFence();
    }

    override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
        if (attachment.Type() == ATTACHMENT_CODE_LOCK && (!HasFullyConstructedGate() || !GetDayZGame().GetCodeLockConfig().CanAttachToGates())) { return false; }
        return super.CanReceiveAttachment(attachment, slotId);
    }

    override void OnPartDismantledServer(notnull Man player, string part_name, int action_id) {
        ConstructionPart constrution_part = GetConstruction().GetConstructionPart(part_name);

        if (constrution_part.IsGate()) {
            if (IsCodeLocked()) {
                CodeLock codelock = CodeLock.Cast(GetCodeLock());
                codelock.UnlockServer(player, this);
            }
        }
        super.OnPartDismantledServer(player, part_name, action_id);
    }

    override void SetActions() {
        super.SetActions();
        AddAction(ActionInteractLockOnFence);
        AddAction(ActionManageLockOnFence);
        AddAction(ActionLockAdminOnFence);
    }
}