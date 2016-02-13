class RadioForm extends React.Component{

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
		this.state= {value:defaultValue};
    }

	onChangeHandler(obj){
		console.log("onChangeHandler");
		console.log(obj);
		this.setState({
			value: obj.target.value
		});  
	}

	render(){
		console.log("render");
		var self= this;
		var radioOptions=this.props.options.map(function(opt){
			return(
				<div className="input-span" key={opt.value} >
					<input type="radio" name="activities" value={opt.value} onChange={self.onChangeHandler} defaultChecked={(opt.value === self.state.value)} />
					<span>{opt.name}</span>
				</div>
			);
		});
		return (
			<div id="radio-form" className="subForm">
				<span id="form-question">{this.props.msg}</span>
				{radioOptions}
			</div>
		);
	}
}