class SelectForm extends React.Component{

	constructor(props) {
        super(props);
        var defaultValue = null;
		var isDefault = false;
		this.props.options.map(function(opt){
			isDefault = (!!opt.isDefault) && !isDefault ; //first isDefault, will be checked
			if(isDefault){
				defaultValue=opt.value;
			}
		});

		this.setState({
			value: defaultValue
		});  
    }
    
	getInitialState(){
		var defaultValue = null;
		var isDefault = false;
		this.props.options.map(function(opt){
			isDefault = (!!opt.isDefault) && !isDefault ; //first isDefault, will be checked
			if(isDefault){
				defaultValue=opt.value;
			}
		});
		return {
			value: defaultValue
		};
	}

	onChangeHandler(obj){
		console.log("onChangeHandler");
		console.log(obj);
		this.setState({
			value: obj.target.value
		});  
	}

	render(){
		var self = this;
		var selectOptions = this.props.options.map(function(opt){
			return(<option name="places" key={opt.value} value={opt.value} >{opt.name}</option>);
		});
		return (
			<div id="selectForm" className="subForm">
				<span id="form-question">{this.props.msg}</span>
				<select defaultValue={this.state.value} onChange={self.onChangeHandler} >
					{selectOptions}
				</select>
			</div>
		);
	}
}