modded class DayZGame {

    protected ref DrugsPLUSConfig DPConfig;

    ref DrugsPLUSConfig GetDrugsPLUSConfig() {
        return DPConfig;
    }

    void SetDrugsPLUSConfig(ref DrugsPLUSConfig dp_config) {
        DPConfig = dp_config;
    }
}